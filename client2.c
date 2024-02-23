#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(){
	int sd,cd;
	char buf[100]={0};
	struct sockaddr_in addr;
	sd=socket(AF_INET,SOCK_STREAM,0);
	printf("sd=%d\n",sd);
	printf("Socket created\n");
addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("10.1.136.225");
	addr.sin_port=8900;//higher than 8080

if(connect(sd,&addr,sizeof(addr))==-1){
	perror("");
//	exit(0);
}
else{
	printf("SErver accepted the connection\n");
	while(1){
scanf("%s",buf);
write(sd,buf,strlen(buf)+1);
printf("client writes\n");
	}
}
close(sd);
}
