#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(){
	int sd,cd;
	char rbuf[100]={0};
	struct sockaddr_in addr;
	int count=0;
	sd=socket(AF_INET,SOCK_STREAM,0);
	printf("sd=%d\n",sd);
	printf("Socket created\n");
addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("10.1.136.225");
	addr.sin_port=8900;//higher than 8080


	if(bind(sd, &addr,sizeof(addr))==-1){
		perror("");
		exit(0);
	}  //binded....
	printf("Socket is binded with ip and port number\n");
	listen(sd,10);//take socket to listening....
	printf("Socket in listening mode\n");
	printf("Waiting for clients\n");
	while(1){
cd=accept(sd,0,0);
printf("Client request accepted\n");
count++;
int i=fork();
if(i==0){

while(1)
{
	read(cd,rbuf,100);
	printf("REda datafrom client %d=%s\n",count,rbuf);
}
}
else{
	close(cd);
}
}
close(sd);
}
