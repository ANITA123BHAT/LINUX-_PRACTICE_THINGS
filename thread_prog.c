#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int i,n,j;
int main(){
	pthread_t a_thread; //thread declaration..
	pthread_create(&a_thread,NULL,thread_function,NULL);//thread is created 
	//a_thread is a thread variable to store id of thread
	//NULL attributes for an thread here NULL means default attribute
	//name of function which contains whatever the thread funtion to do..
	//NULL 4th para- input to the function.. 
	pthread_join(a_thread,NULL);//process wait for thread to finish..
	printf("Insie the main\n");
	for(j=20;j<25;j++){
		printf("%d\n",j);
		sleep(1);
	}
}
void *thread_function(void *arg){
	printf("Inside the thread\n");
	for(i=0;i<5;i++){
	printf("%d\n",i);
	sleep(1);
	}

}
