#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
	pid_t q;
	q=fork();
	if(q==0){
		printf("I am child having an id::%d\n",getpid());

sleep(10);
execl("/bin/ps","ps",NULL);
	}//child
	else{//parent
		wait(NULL);
		printf("I am parent having id:%d\n",getpid());
	}
}
