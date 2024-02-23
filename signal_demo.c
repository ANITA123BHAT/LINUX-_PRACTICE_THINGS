#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void myHandler1(int signum);
void myHandler2(int);
void myHandler1(int signum){
	printf("signal handled\n");
	printf("IN myHnadler1 function\n");
	printf("signal number=%d\n",signum);
//	exit(0);
	signal(SIGKILL,myHandler2);
}
void myHandler2(int signum){
	printf("signal\n");
	printf("signal in myhandler2\n");
	signal(SIGKILL,myHandler1);
}
int main()
{
	int count=0;
//	signal(SIGALRM,myHandler);
//signal(SIGALRM,SIG_IGN);//signa l to ignore..
//signal(SIGALRM,SIG_DFL); to ignore...signal..
//signal(SIGINT,myHandler1);
//signal(SIGKILL,myHandler1);
signal(SIGSTOP,myHandler1);
	printf("IN main application\n");
//alarm(12);
	while(1){
		printf("in while loop\n");
		printf("value of count=%d\n",count);
		count++;
		sleep(1);
	}
	printf("end\n");
}
