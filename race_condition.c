//program to create a race condition..
//program to create two thread :one to increament the value of shared variable and second on eto decreament the value of shared variable..

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared=1;// shrared variable..
int main(){
	pthread_t thread1,thread2;//two threads
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Final value of shared is %d\n",shared);
}
void *fun1(){
	int x;
	//local variable
	x=shared;//thread one reads value of shread variable. initial value of shared variable =1
	printf("Thread1 reads the value of shared variable as %d\n",x);//1
	x++;
	printf("local updation by thread1:%d\n",x);
	sleep(1);//thread one is preempted by thread2..
	//overlapping the working of thread it will give chance to second thread to run..
	//till not updtaed the calue of shared var now it call thread2 i.e fun2() 
	//here value of x i supdated to 2 but not shared yet..
	
	shared=x;//thread one upadted the value of shared variable.. to 2 now it become 2.. once it get finish it will come back to thread2..
	printf("value of shared variable updated by thread1 is::%d\n",shared);
}

void *fun2(){
int y;
y=shared;//thread two reads the value of shared variable..  value 1
y--;//thread2 decreaments...
printf("local updation by thread2::%d\n",y);
sleep(1);// control come to thread1  
shared=y;
printf("value of shared variable updated by thread2 is:%d\n",shared);

}

