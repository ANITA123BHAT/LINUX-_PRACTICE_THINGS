#include<unistd.h>
//pipe will open uni directionaldata  channel to communicate withn two process 
//this pipe which return 2 file discriptor one for writeing end another one reading end
//fd[1]=writing end
//fd[0]=reading end
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int fd[2],n;
char buffer[100];
pid_t p;
pipe(fd);
p=fork();
if(p>0){
	printf("Passing value to child\n");
	write(fd[1],"Hello\n",6);//fd[1] writing end
//	write to send data..
}else{//child process

	printf("\n child recieve data\n");
	n=read(fd[0],buffer,100);
	//recive end rwad to recieve..
	write(1,buffer,n);
}
}
