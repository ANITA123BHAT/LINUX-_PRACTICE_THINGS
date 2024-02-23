#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
int main(){
	pid_t q,w;
	int w1,wstatus;
	printf("\nbefore fork\n");
	q=fork();
	if(q==0){//choild process
		sleep(10);
               	printf("i am child having an id:%d\n",getpid());
		printf("My parent id:%d\n",getppid());
	}
	else{
	//	wait(NULL);
		w1=wait(&wstatus);
		printf("status is:%d\n",WIFEXITED(wstatus));
		printf("status is:%d\n",w1);
		printf("I am parent having an id:%d\n",getpid());
		printf("i am having an cild its is::%d\n",q);
	}
	printf("common\n");
}
