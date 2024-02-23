#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
//#include<sys/stat.h>
#include<sys/socket.h>
int main(){
	//STEPS:
//INitialize the socket
//Initialize the environment for sock address structure
//bind the socket to the local port
//listen the request from client (queue the requests)
//keeo wiating for new request and proceed as per the request
//**********************************
WSADATA ws;
if(WSAStartup(

int nSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(nSocket<0){
	printf("socket is not opened\n");
}
else{
	printf("the socket opened successfully\n");
}

}
