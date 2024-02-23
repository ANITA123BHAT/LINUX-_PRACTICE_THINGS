#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/wait.h>
int main(){
	pid_t q,p;// data type  pid_t
	q=fork();
	if(q<0){
		perror(" ");
	}
	else if(q==0){
		sleep(3);
		printf("I am first child having a pid::%d\n",getpid());
		printf("I am first and my parent:%d\n",getppid());
	}
	else{
		p=fork();//child2...
		if(p==0){
			sleep(4);
			printf("iI am secind child pid is::%d\n",getpid());
			printf("I am second child and my parent ::%d\n",getppid());
		}
		else{
			waitpid(p,NULL,0);
                    
		}
		printf("parent having id:%d\n",getpid());
		printf("my first child is:%d\n",q);
	printf("common\n");

}
}
