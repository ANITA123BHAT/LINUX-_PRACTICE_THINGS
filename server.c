#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){
	int sd,cd;//socket description and client desc
sd=socket(AF_INET,SOCK_STREAM,0);//0 for choose a protocol by system itself ..
printf("sd= %d \n",sd);
}
