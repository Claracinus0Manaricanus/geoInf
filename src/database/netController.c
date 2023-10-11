#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "dataController.h"
#include "../include/utility.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//constants
#define VAL_READY -3
#define VAL_DONE -2
#define VAL_ERROR -1

#define WAITFOR 999999

//network
int TCPListener(uint32_t ip, uint16_t port);
//signal utility
void intSignal(int sigVal);
//parsing
int parseRequest(const char* request, char*** retArgs, int* size);//scans request and puts arguments to retArgs

//global variables
unsigned char run=1;





int main(int argc, char** argv){
    //constants
    const int READY=VAL_READY;
    const int DONE=VAL_DONE;
    const int ERROR=VAL_ERROR;

    //port
    uint16_t port=8080;
    if(argc>1){//if an argument is given
        port=(uint16_t)atoi(argv[1]);
    }

    //TCP setup
    uint32_t ipAddr=0;
    inet_pton(AF_INET,"0.0.0.0",&ipAddr);
    int TCP_Server=TCPListener(ipAddr,(port<<8)+(port>>8));

    //signal handler
    signal(SIGINT,intSignal);

    //vars
    int clsfd;//client socket file descriptor
    int parseResult=0,argLength=0,clientVal=0,counter=0;
    struct tableElement dataHolder;
    char clientMessage[256]={0};//from client
    char serverMessage[1024]={0};//to client
    char** parseArgs=NULL;
    char** names=NULL;int namesLength=0;

    //answering requests
    while(run){
        //resetting
        counter=0;
        parseResult=VAL_ERROR;
        clientVal=VAL_DONE;

        //client connection
        printf("Waiting for a Client.\n");
        while((clsfd=accept(TCP_Server,NULL,NULL))==-1){
            
        }
        printf("Client connected. Sending VAL_READY.\n");

        //communication
        write(clsfd,&READY,sizeof(int));
        while(recv(clsfd,clientMessage,256,MSG_DONTWAIT)==-1){//getting request //change with socket option SO_RCVTIMEO
            if(counter>WAITFOR){
                clientVal=VAL_ERROR;//to stop sending data
                printf("Failed acquiring request from client. Closing connection.\n");
                break;
            }
            counter++;
        }
        counter=0;

        if(clientVal!=VAL_ERROR){
            printf("Client request:\n%s\n",clientMessage);
            parseResult=parseRequest(clientMessage,&parseArgs,&argLength);
        }

        switch(parseResult){
            case COMMAND_GET:

            break;
            case COMMAND_SCAN://scans a table for element names
                if(argLength<1)
                    break;
                if(getTableElementNames(parseArgs[0],&names,&namesLength)!=0)
                    break;

                write(clsfd,&namesLength,sizeof(int));
                for(int i=0;i<namesLength;i++){
                    clientVal=strlen(names[i]);

                    write(clsfd,&clientVal,sizeof(int));
                    printf("sending: %s\n",names[i]);
                    write(clsfd,names[i],clientVal);

                    while(recv(clsfd,&clientVal,sizeof(int),MSG_DONTWAIT)==-1){
                        if(counter>WAITFOR){
                            clientVal=VAL_ERROR;
                            break;
                        }
                        counter++;
                    }counter=0;

                    if(clientVal==READY)continue;
                    else break;
                }
            break;
        }

        //disconnect client
        if(clientVal==VAL_READY){
            printf("Done. Disconnecting client.\n");
            write(clsfd,&DONE,sizeof(int));
        }else{
            printf("An error occured sending VAL_ERROR.\n");
            write(clsfd,&ERROR,sizeof(int));
        }
        close(clsfd);
    }
    
    //termination
    close(clsfd);
    close(TCP_Server);
    //freeGeoObj(&dataHolder);
    return 0;
}






//network
int TCPListener(uint32_t ip, uint16_t port){
    //socket()
    int tmpSFD=socket(AF_INET,SOCK_STREAM,0);//temporary socket file descriptor
    if(tmpSFD==-1){
        printf("socket() failed!\nerrno: %d\n",errno);
        return -1;
    }

    //socket options
    int yes=1;
    if(setsockopt(tmpSFD,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1){
        printf("setsockopt() failed!\nerrno: %d\n",errno);
    }
    
    //address
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=port;
    addr.sin_addr.s_addr=ip;

    //bind()
    if(bind(tmpSFD,(struct sockaddr*)&addr,sizeof(struct sockaddr_in))==-1){
        printf("bind() failed!\nerrno: %d\n",errno);
        close(tmpSFD);
        return -1;
    }
    
    //listen()
    if(listen(tmpSFD,SOMAXCONN)==-1){
        printf("listen() failed!\nerrno: %d!",errno);
        close(tmpSFD);
        return -1;
    }
    
    //return
    return tmpSFD;
}





//signal utility
void intSignal(int sigVal){
    run=0;
}





//parsing
int parseRequest(const char* request, char*** retArgs, int* size){
    //vars
    int i=0,posTmp=0,returnVal=VAL_ERROR;
    char tmpArr[256]={0};
    char** argArr=NULL;//argument holder
    char tmp=0,stage=-1;
    //start
    tmp=request[i];
    while(tmp!=';'&&i<256){
        if(tmp==0){
            returnVal=VAL_ERROR;
            break;
        }
        i++;
        if(tmp!=':'){
            tmpArr[posTmp]=tmp;
            posTmp++;
        }else{
            posTmp=0;
            switch(stage){
                case -1://main command
                    if(strcmp(tmpArr,"get\0")==0){
                        returnVal=COMMAND_GET;
                    }else if(strcmp(tmpArr,"scan\0")==0){
                        returnVal=COMMAND_SCAN;
                    }
                    stage=0;
                break;
                default:
                    argArr=realloc(argArr,sizeof(char*)*(stage+1));
                    argArr[stage]=calloc(strlen(tmpArr)+1,sizeof(char));
                    memcpy(argArr[stage],tmpArr,strlen(tmpArr));
                    stage++;
                break;
            }
            memset(tmpArr,0,64);
        }
        tmp=request[i];
    }
    //return
    free((*retArgs));
    (*retArgs)=argArr;
    (*size)=stage;
    return returnVal;
}