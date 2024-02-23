#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int res,n;
	char buffer[100];
	res=open("fifo1",O_NONBLOCK|O_RDONLY);
	n=read(res,buffer,100);
	printf("reader process having PID %dstarted\n",getpid());
	printf("data received by receiver %d is:%s\n",getpid(),buffer);

}
