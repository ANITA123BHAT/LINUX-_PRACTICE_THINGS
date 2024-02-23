
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void myHandler(int signum){
	printf("signal number:%d\n",signum);
	printf("completed....\n");
	exit(0);

}
int main(){
	int i,j,k;
	i=fork();
	if(i==0){
		printf("child process1.....\n");

	}
	else{
		j=fork();
		if(j==0){
			printf("child process2..\n");
		}
		else{
			k=fork();
			if(k==0){
				printf("choild process3....\n");
			}
			else{
			

	signal(SIGCHLD,myHandler);
	while(1);

			}
		}
	}
}
