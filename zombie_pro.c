#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t p;
	p=fork();
	if(p==0){//child
		printf("I ma child having an pid:%d\n",getpid());
		printf("My parent Id is:%d\n",getppid());
	}
	else{
		sleep(10);//to make zombie to child process..
		wait(NULL);
		printf("UI ma parwnt having an PID::%d\n",getpid());
		printf("My child having an PId::%d\n",p);
	}

}
