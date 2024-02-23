#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int n,f,f1;
	char buf[50];
	f=open("seeking",O_RDWR);
//	read(f,buf,10);
//	write(1,buf,10);
f1=	lseek(f,-20,SEEK_END);//skip 10 character from cur
printf("\npointer piostin is:%d\n",f1);
read(f,buf,19);
	write(1,buf,19);
}
