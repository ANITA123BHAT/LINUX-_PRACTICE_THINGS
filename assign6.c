#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(){
	printf("IN main function..\n");
	printf("Before fork()\n");
	int i=fork();
	int j=fork();
	int k=fork();
		printf("child process1..\n");
		printf("child process1 gets waited to complet\n");
	
		
		sleep(15);
		printf("parent proces..\n");
		printf("end of parent process..\n");
		waitpid(j,0,0);
		printf("parent waited for atleast one process of child to compalte\n");
}
