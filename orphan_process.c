#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
int main(){
	pid_t p;
	p=fork();
	if(p==0){
		sleep(10);
		printf("I am child having an PID::%d\n",getpid());
		printf("My paent id::%d\n",getppid());
	}
	else{
		sleep(2);
		//wait(NULL);
		printf("I am Parent having PId:%d\n",getpid());
		printf("My child PID is::%d\n",p);
	}
}
