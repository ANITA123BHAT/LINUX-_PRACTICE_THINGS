#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

static void *thread_fn_callback(void *arg){
 char *input=(char *)arg;
 int a=0;
 while(a<10){
 printf("input string :%s\n",input);
 sleep(1);
 if(a==5){
 	pthread_exit(0);
 }

 a++;
 }

}


void thread1_create(){
pthread_t pthread1;//thread handler is pthread_t 
static char *thread_input1="I ma thread no 1";
//take only static not local variable
int rc=pthread_create(&pthread1,NULL,thread_fn_callback,(void *)thread_input1);

//memory which is provided as input to the thread is always heap or static not an local varable . it is dynamically allocated. it is fork point.
//thtead_fn_callback() is the new thread going to execute.
if(rc!=0){
printf("error\n");
exit(0);
}

}


int main(int argc, char **argv){
	
	thread1_create();
	printf("main fn paused\n");
	pause();//no to terminate main function to wait for thread to complete.
	pthread_exit(0);
	return 0;
}
