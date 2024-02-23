//program to creat a thread to add two number 
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int num[2]={3,5};
int main(){
	pthread_t a_thread;
	void *result;
	pthread_create(&a_thread,NULL,thread_function,(void *)num);//thread is created
	pthread_join(a_thread,&result);
	printf("Inside the main process\n");
	printf("THread returned:%s\n",(char *)result);
}
void *thread_funtion(void *arg){//the work to be done by the thread is defined in this fucntion..
	printf("\ninside the thtead funtion\n");
	int *x=arg;
	int sum=x[0]+x[1];
	printf("sum is:%d\n",sum);
	pthread_exit("Sum calculated");//it will return back to main after executing sum calculated statement.
}
