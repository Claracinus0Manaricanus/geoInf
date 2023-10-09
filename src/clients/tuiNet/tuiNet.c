#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>




//constants
#define VAL_READY -3
#define VAL_DONE -2
#define VAL_ERROR -1

const char* HELP_MESSAGE=
"Tool for accessing geoInf server.\n"
"usage tuiNet <server ip> <server port> <command>\n"
"note: put the command in '' while giving it as an argument\n"
"supported commands:\n"
"- get: format: get:<tableName>:<elementName>:;\n"
"- scan: format: scan:<tableName>:;\n";





int main(int argc, char** argv){
    //reading arguments
    if(argc<4){
        printf("not enough arguments!\n%s",HELP_MESSAGE);
        return -1;
    }
    uint16_t port=atoi(argv[2]);

    //connecting to server
    int clsfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=(port<<8)+(port>>8);
    inet_pton(AF_INET,argv[1],&addr.sin_addr.s_addr);

    if(connect(clsfd,(struct sockaddr*)&addr,sizeof(struct sockaddr_in))==-1){
        printf("connection error!\n");
        close(clsfd);
        return -1;
    }

    //buffers
    char reqMessage[256]={0};//request message
    char clientMessage[1024]={0};//client respond
    int serverVal=0,length=0;//for receiving numbers from server

    memcpy(reqMessage,argv[3],strlen(argv[3]));

    //sending request
    read(clsfd,&serverVal,sizeof(int));//seeing if server is ready
    if(serverVal==VAL_READY){
        write(clsfd,reqMessage,256);
    }

    //communication
    const int READY=VAL_READY;
    char run=1;
    char** vals=NULL;
    while(run){
        read(clsfd,&serverVal,sizeof(int));
        if(serverVal==VAL_DONE||serverVal==VAL_ERROR)break;
        for(int i=0;i<serverVal;i++){
            //receiving
            read(clsfd,&length,sizeof(int));
            read(clsfd,clientMessage,length);
            //assigning
            vals=realloc(vals,sizeof(char*)*(i+1));
            vals[i]=calloc(sizeof(char)*(length+1),sizeof(char));
            memcpy(vals[i],clientMessage,strlen(clientMessage));
            //cleanup
            memset(clientMessage,0,1024);
            write(clsfd,&READY,sizeof(int));
        }
        length=serverVal;
    }

    //output
    for(int i=0;i<length;i++){
        printf("%s\n",vals[i]);
    }

    //termination
    printf("\n");
    close(clsfd);
    return 0;
}