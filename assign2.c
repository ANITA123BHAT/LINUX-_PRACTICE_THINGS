#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int i;
	printf("in main function\n");
	printf("before fork()\n");
	i=fork();
	if(i==0){
		sleep(10);
		printf("child process id in child process:%d\n",getpid());
		printf("parent processid in child process:%d\n",getppid());
	}
	else{
		printf("chilfd processid in parent process:%d\n",i);
		printf("parent process id:%d\n",getpid());
		wait(0);
	}

}
