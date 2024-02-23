#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int num[2]={3,5};//interger array..

int main(){
	pthread_t a_thread;//thread declaration..
	void *result;
	pthread_create(&a_thread,NULL,thread_function,(void *)num);//thread is created.. 4th ara- pas sarray to a function 
	pthread_join(a_thread,&result);//process wait till thread to finish..
 	printf("Inside the main process\n");
	printf("Thread returns:%s\n",(char *)result);
return 0;
}
void *thread_function(void *arg){
	printf("Inside the thread\n");
	int *x=arg;
	int sum=x[0]+x[1];
	printf("Sum is::%d\n",sum);
	pthread_exit("sum_calculated");
}
//if thread return from within it to the main process it uses pthread_exit() function..
