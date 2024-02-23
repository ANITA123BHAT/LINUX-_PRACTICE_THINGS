#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	int fd1;
	char buf[50];//f11 is fifo file....
	fd1=open("f11",O_RDONLY);
read(fd1,buf,50);
printf("read data %s\n",buf);
close(fd1);
}
