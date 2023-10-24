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
#include <sys/time.h>

//constants
#define VAL_READY -3
#define VAL_DONE -2
#define VAL_ERROR -1

#define WAITFOR 5

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
    int TCP_Server=TCPListener(0,(port<<8)+(port>>8));

    //signal handler
    signal(SIGINT,intSignal);

    //vars
    int clsfd;//client socket file descriptor
    int parseResult=0,argLength=0,clientVal=0,error=0;
    struct tableElement dataHolder;
    setNULLGeoObj(&dataHolder);
    char networkBuffer[1024]={0};//for communication
    char** parseArgs=NULL;
    char** queryData=NULL;int dataLength=0;
    struct sockaddr_in clientAddr;uint32_t clientAddrLen=0;

    //answering requests
    while(run){
        //resetting
        error=0;
        parseResult=VAL_ERROR;

        //client connection
        printf("Waiting for a Client.\n");
        while((clsfd=accept(TCP_Server,(struct sockaddr*)&clientAddr,&clientAddrLen))==-1){}
        printf("Client connected.\n");
        printf("IPV4: %s\n",inet_ntoa(clientAddr.sin_addr));
        printf("Sending VAL_READY.\n");

        //communication
        write(clsfd,&READY,sizeof(int));
        if(recv(clsfd,networkBuffer,256,0)==-1){//getting request
            error=1;//raise error integer
            printf("Failed acquiring request from client. Closing connection.\n");
        }

        if(!error){
            printf("Client request: %s\n",networkBuffer);
            parseResult=parseRequest(networkBuffer,&parseArgs,&argLength);
        }

        switch(parseResult){
            case COMMAND_GET:
                if(argLength<2){
                    error=1;
                    break;
                }
                if(getFromTable(parseArgs[0],parseArgs[1],&dataHolder)!=0){
                    write(clsfd,&ERROR,sizeof(int));
                    error=1;
                }else{
                    clientVal=4;

                    //for iterative usage
                    queryData=(char**)calloc(4,sizeof(char*));
                    queryData[0]=dataHolder.name;
                    queryData[1]=dataHolder.climate;
                    queryData[2]=dataHolder.soil;
                    queryData[3]=dataHolder.flora;

                    write(clsfd,&clientVal,sizeof(int));
                    for(int i=0;i<4;i++){
                        clientVal=(int)strlen(queryData[i]);

                        write(clsfd,&clientVal,sizeof(int));
                        printf("sending: %s\n",queryData[i]);
                        write(clsfd,queryData[i],clientVal);

                        if(recv(clsfd,&clientVal,sizeof(int),0)==-1){
                            error=1;
                            break;
                        }
                    }

                    free(queryData);
                    freeGeoObj(&dataHolder);
                }
            break;

            case COMMAND_SCAN://scans a table for element names
                if(argLength<1){
                    error=1;
                    break;
                }
                if(getTableElementNames(parseArgs[0],&queryData,&dataLength)!=0){
                    error=1;
                    break;
                }

                write(clsfd,&dataLength,sizeof(int));
                for(int i=0;i<dataLength;i++){
                    clientVal=(int)strlen(queryData[i]);

                    write(clsfd,&clientVal,sizeof(int));
                    printf("sending: %s\n",queryData[i]);
                    write(clsfd,queryData[i],clientVal);

                    if(recv(clsfd,&clientVal,sizeof(int),0)==-1){
                        error=1;
                        break;
                    }
                }
                free(queryData);
            break;

            case VAL_ERROR:
            error=1;
            break;
        }

        //disconnect client
        if(error){
            printf("An error occured sending VAL_ERROR.\n");
            write(clsfd,&ERROR,sizeof(int));
        }else{
            printf("Done. Disconnecting client.\n");
            write(clsfd,&DONE,sizeof(int));
        }
        close(clsfd);
    }
    
    //termination
    close(clsfd);
    close(TCP_Server);
    freeGeoObj(&dataHolder);
    //cleanup
    free(parseArgs);
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
    int sockVal=1;
    if(setsockopt(tmpSFD,SOL_SOCKET,SO_REUSEADDR,&sockVal,sizeof(int))==-1){
        printf("setsockopt(SO_REUSEADDR) failed!\nerrno: %d\n",errno);
    }
    struct timeval waitTime;//timeout variable
    waitTime.tv_sec=WAITFOR;
    waitTime.tv_usec=0;
    if(setsockopt(tmpSFD,SOL_SOCKET,SO_RCVTIMEO,&waitTime,sizeof(struct timeval))==-1){
        printf("setsockopt(SO_RCVTIMEO) failed!\nerrno: %d\n",errno);
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
                    argArr[stage]=calloc((int)strlen(tmpArr)+1,sizeof(char));
                    memcpy(argArr[stage],tmpArr,(int)strlen(tmpArr));
                    stage++;
                break;
            }
            memset(tmpArr,0,64);
        }
        tmp=request[i];
    }
    //return
    (*retArgs)=argArr;
    (*size)=stage;
    return returnVal;
}