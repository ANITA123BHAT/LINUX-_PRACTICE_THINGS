#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/sem.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int shmkey=65535,semkey=65530;
	int shmid,semid;


	shmid=shmget(shmkey,3900,IPC_CREAT|0777);//created shared memeory...
	printf("shred memory id:%d\n",shmid);

	semid=semget(semkey,1,IPC_CREAT|0777);//create semaphore array of 1 semaphore here 1 means number of semaphores......
	printf("shred memory id:%d\n",semid);

	semctl(semid,0,SETVAL,1);
	printf("INitial value fpor semaphore is set\n");

}
