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
#define VAL_READY 1
#define VAL_DONE 2

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
    int parseResult=0,argLength=0;
    struct tableElement dataHolder;
    char clientMessage[256]={0};//from client
    char serverMessage[1024]={0};//to client
    char** parseArgs=NULL;

    //answering requests
    while(run){
        //client connection
        clsfd=accept(TCP_Server,NULL,NULL);

        //communication
        write(clsfd,&READY,sizeof(int));
        read(clsfd,clientMessage,256);//getting request
        parseResult=parseRequest(clientMessage,&parseArgs,&argLength);

        for(int i=0;i<argLength;i++){
            printf("%s\n",parseArgs[i]);
        }

        switch(parseResult){

        }

        //disconnect client
        write(clsfd,&DONE,sizeof(int));
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
    raise(SIGTERM);
}





//parsing
int parseRequest(const char* request, char*** retArgs, int* size){
    //vars
    int i=0,posTmp=0,returnVal=-1;
    char tmpArr[64]={0};
    char** argArr=NULL;//argument holder
    char tmp=0,stage=-1;
    //start
    tmp=request[i];
    while(tmp!=';'){
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