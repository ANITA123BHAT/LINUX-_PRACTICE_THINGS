#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int fd1;
	fd1=open("f11",O_WRONLY);
	write(fd1,"HELLO SASKEN",12);
	printf("process1 write:\n");
	close(fd1);
}
