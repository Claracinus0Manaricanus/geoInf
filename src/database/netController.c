#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "dataController.h"
#include "../include/utility.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//network
int TCPListener(uint32_t ip, uint16_t port);
//signal utility
void intSignal(int sigVal);

//global variables
unsigned char run=1;

int main(int argc, char** argv){
    //setting arguments as port
    uint16_t port=8080;
    if(argc>1){
        port=(uint16_t)atoi(argv[1]);
    }

    //TCP setup
    uint32_t ipAddr=0;
    inet_pton(AF_INET,"127.0.0.1",&ipAddr);
    int TCP_Server=TCPListener(ipAddr,(port<<8)+(port>>8));

    //signal handler
    signal(SIGINT,intSignal);

    //vars
    char i=0;
    int clsfd;
    struct tableElement dataHolder;

    //answering requests
    while(run){
        clsfd=accept(TCP_Server,NULL,NULL);
        run=2;
        while(run>1){
            run=1;
        }
        close(clsfd);
    }
    
    //termination
    close(TCP_Server);
    freeGeoObj(&dataHolder);
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