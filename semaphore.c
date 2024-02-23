//program for process synchronization using semaphores
//program to creat a two threads
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
void *fun1();
void *fun2();
int shared=1;//shared variable..
sem_t s;//semaphore variable..
int main(){
	sem_init(&s,0,1);//initializing the semaphore variable 1st args is address of variable, 2nd is 0(shared btw threads) or non zero(shraed btw process), 3rd arg is the initial value of semaphore variable. so binary value 1 means semaphore var is free 0 means used..

	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Final value of shared is::%d\n",shared);

}

void *fun1(){
	int x;
	sem_wait(&s);//executes wait operation on s
	x=shared;// thread1 reads value of shred variable
	printf("LOcal updation by thread1 ::%d\n",x);
	x++;//thread1 increaments its value..
	printf("local updation by thread1:%d\n",x);
	sleep(1);
	shared=x;
	printf("value of shared varible updated by thread1::%d\n",shared);
	sem_post(&s);
}

void *fun2(){
int y;
sem_wait(&s);
y=shared;//thread2 reads value of shared variable
printf("thread2 reads the value as %d\n",y);
y--;
printf("local updation by thread2::%d\n",y);
sleep(1);//thread2 is preempted by thread 1
shared=1;// thread2 updates the value of shared varible..
printf("value of shared varible updated by thread2 is::%d\n",shared);
sem_post(&s);
}
