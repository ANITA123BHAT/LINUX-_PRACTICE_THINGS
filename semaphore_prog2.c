//process synchronization using mutex locks...

//program flow:
//1.pthread_mutex_t L;
//2.pthread_mutex_init()
//3.create two thread
//4.thread 1
//4.1) pthread_mutext_lock()
//4.2) crtical section..
//4.3) pthread_mutex_unlock()..
//5.thread2
//5.1,5.2,5.3.. same as 4.1...
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared=1;//shared variable..
pthread_mutex_t l;//mutex lock
int main(){
pthread_mutex_init(&l,NULL);//Initialing the mutex locks.. 
//1st para- address of teh mutex lock variable.. and 2nd -attributes of teh mutex lock.. NULL is default attribute..
pthread_t thread1, thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("final valye of shared is::%d:\n",shared);//prints the last updated value of shared variable..

}

void *fun1(){
int x;
printf("THread1 trying to aquire lock\n");
pthread_mutex_lock(&l);//thread one aquires the lock. now thread2 will not be able to aquire thread1
//lock untill it is unlock by thread..
printf("thread1 acquires the lock\n");
x=shared;
printf("Thread1 reads the value of an varibel as :%d\n",x);
x++;
printf("LOcal updation by thread1::%d\n",x);
sleep(1);
shared=x;
printf("Value of sharedev varible updated by thraed1::%d\n",shared);
pthread_mutex_unlock(&l);
printf("Thread1 release dthe lock\n");
}

void *fun2(){
int y;
printf("Thread2 trying to aquire lock\n");
pthread_mutex_lock(&l);
printf("THread2 acquires the lock\n");
y=shared;
printf("thread2 reads the value of shared value::%d\n",y);
y--;
printf("updated value of y by thread2::%d\n",y);
sleep(1);
shared=y;
printf("value of shared varibel by thread2:%d\n",shared);
pthread_mutex_unlock(&l);
printf("THread2 released the lock\n");
}
