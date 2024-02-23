#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	int shmkey=65535,semkey=65530;
	int shmid,semid;
	struct sembuf s1;
	char *ptr;
	char data[100]="HELLO SHARED MEMORY CONTOLL BY SEMAPHORE";
	shmid=shmget(shmkey,0,0);
	printf("Shared memory id:\n",shmid);
	
	semid=semget(semkey,0,0);
	printf("semaphore memory id:%d\n",semid);
	printf("process1 is tring to  take  a semaphore:\n");
s1.sem_num=0;
s1.sem_op=-1;
s1.sem_flag=0;
semop(semid,&s1,1);
printf("Process1 takes semaphores\n");
ptr=shmat(shmid,0,0);
for(int i=0;data[i];i++){
	*(ptr+i)=data[i];
	sleep(1);
	printf("process1 writing...\n");
}
*(ptr+i)='\0';
printf("Process1 finish wrting\n");
	printf("process1 is tring to release a semaphore:\n");
s1.sem_num=0;
s1.sem_op=+1;
s1.sem_flag=0;
semop(semid,&s1,1);
printf("Process1 releases semaphores\n");

}
