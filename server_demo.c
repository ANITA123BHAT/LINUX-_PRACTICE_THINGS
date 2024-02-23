//server

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>

int main(int argc, char* argv[]){
//all args passeed in cmd line will will stored in argsv[]
//argc is the argument counter will have value 2 port number of server and program name
  //step1:create a socket
 int sockfd,newsockfd,portno,n;
 struct sockaddr_in serv_addr,client_addr;//structure variable to store sever variable and other one when we accept the client request .//server_addr =store server info
 char buffer[1024];// to store data .. send /recieve data
 socklen_t len;//to store size of an address 32bit
//check for appropriate no.of command line inputs
if(argc<2){
	printf("provide the required command-line input as <filename.c><server_IP_addr><portno>\n");
	exit(1);
}
portno=atoi(argv[1]);// conver from string to equilent interger
sockfd=socket(AF_INET,SOCK_STREAM,0);
//1st para:IP V4 version =AF_INET, 2nd para: SOCK_STREAM= TCP connect, 3rdpara: default protocall IP(0); so socket created 
//if socket is created properrly than sockfd will store value 1 otherwise; value of -1;

//check if sockt if created properly
if(sockfd<0){
	printf("ERror in opening a socket\n");
	exit(1);
}
//step2: build the structure for server adress
serv_addr.sin_family=AF_INET;//
serv_addr.sin_addr.s_addr=INADDR_ANY;//sin_addr is a structure and s_addr is a variable to store IP address.
//INADDR_ANY to store any IP adress of system.
serv_addr.sin_port=htons(portno);
//sin_port=to store port number htons=to store it in network formate

//step3:
//bind the socket to the address and port number specified in structure
if(bind(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))<0){
	//here 2nd argument is casted 3rd var is sizeof struct variable. 
	//if binding is proper 1;other wise -1 i.e is error in binding
}

//step4: listen to any incoming client
listen(sockfd,5);
//5 means doesn't mean that it can handle 5 client at a time but it will maintain a 5 queue and it will handle all but one at a time from those 5 request so 5 is   queue.

len=sizeof(client_addr);

//step5: accept incoming call
newsockfd=accept(sockfd,(struct sockaddr *)&client_addr,&len);
//whenever client request new socket is created so we created structure client_addr, sizeof that structure variable is 3rd parameter.i.e len

//check if the client socket is created properly
if(newsockfd<0){
	printf("Error in accepting request..\n");
	exit(1);
}

//configuration is done....

while(1){//seding and recieving is continues so we take while(1);
	bzero(buffer,1024);// clear buffer
		//now reda some data from client....
		n=read(newsockfd,buffer,1024);
	//read adata in 1st arg, 2nd to store data, 3rd is sizeof buffer
	if(n<0){
 		printf("error in reading...\n");
		exit(1);
	}

	//print client request data...
	printf("\nclient -->%s\n",buffer);

	bzero(buffer,1024);// clear buffer
	//else we can have one for reading one for write ..so no need to clear buffer
	//now we write some data to client...
	fgets(buffer,1024,stdin);//to read whatever we write.. since stdin we are going to read from console not from any file ..
//stdin read from console and store it in buffer

	n=write(newsockfd,buffer,1024);
	if(n<0){
		printf("\nerror in writing..\n");
		exit(1);
	}

	//detec end of conversation...
	if(!strncmp("bye",buffer,3)){
		break;
	}
}
//if client send bye or first 3 char is bye than ends converstaion from server side.

close(newsockfd);
close(sockfd);
 return 0;
}
