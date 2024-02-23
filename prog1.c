#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
int fd=0;
char ch[50]={0};
if(fd=open("new3",O_RDONLY|O_CREAT)!=-1){
	printf("fd value:%d\n",fd);
}
else{
perror("");
}

read(STDIN_FILENO,ch,50);
write(STDOUT_FILE_NO,ch,50);
while(1);
}


