//proram tom proces synchronization using semaphores...
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared=1;//shared variable..
sem_t s;//semaphore varibale..
int main(){
sem_init(&s,0,1);//initialize semaphore varib;le=1st argument is address  of the semaphore  variable, 2nd is 0|non-zero 
//it has 0 if synchronization or semaphore variable is shared btw thread..
//if want to synchronize three process than value of 2nd para is 3..
//3rd para-initial value of the semaphore  varible.. binary semaphore initial value is 1 means semaphore varibel is free 0 means semaphore  variable is used..

pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Final value of shared is::%d\n",shared);//print the last upadted value of shared variable..
}

void *fun1(){
int x;
sem_wait(&s);//execute wait operation on s bcz s value 0 i.e used.. 
x=shared;//thread1 reads the value of shared var
printf("THread1 reads the value as::%d\n",x);
x++;
printf("\nlocal updation by threda1 is:%d\n",x);
sleep(1);//here it will goto thread2..
shared=x;//now x=1
printf("value of shared variable updated by thread1:%d\n",shared);
sem_post(&s);//now here it simply icreament the value of semaphore varible value back to one.. so control come to thread2..
}

void *fun2(){
int y;
sem_wait(&s);// here still s is 0 so wait tille it wait threa1 come out from sleep().. so thread 1come to execution..
y=shared;//here it come after threa1 so s value is 1 so it starts execution..
printf("thread2 reads the value of semaphore::%d\n",y);
y--;
printf("updated value by thread2:%d\n",y);
sleep(1);
shared=y;
printf("value of shared varible updated by thread2:%d\n",shared);
sem_post(&s);//again icrement the value of s back to 1 
//only one thread can use  asemaphore in it's critical section at one time we have ensure mutual exclusion of both thread..
// so we can avaoid the race condition by using semaphore wait and post condition..
}
