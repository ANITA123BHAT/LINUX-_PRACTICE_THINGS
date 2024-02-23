#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int i;
	printf("IN main application\n");
	printf("Before fork\n");
     i=	fork();
     if(i==0){
	     
printf("chold process\n");
printf("child process id in child process:%d\n",getpid());
printf("parent process id in child process%d\n",getppid());
     }
     else{
	     sleep(40);
	     printf("parent process\n");

printf("child  process id in parent process:%d\n",i);

printf("parent process id in parent process%d\n",getppid());
printf("end of parent process\n");
wait(0);
printf("parent complete after child finish\n");
     }

}
