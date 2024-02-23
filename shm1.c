#include<stdio.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int key=65553;
	int shmid;
	char *ptr;
//	shmid=shmget(key,0,0);
shmid=shmget(key,1800,IPC_CREAT|0777);//create a new shred memory..
	printf("shared memoryid is =%d\n",shmid);
	//attaching to shred memor to my process to read or write than dettach.
	//ptr=shmat(shmid,0,0) hereNULL| 0-shred memory to attach in some place of process
	//another 0 for attach mode SHM_RDONLY
	
	ptr=shmat(shmid,NULL,0);// 0 means both read and write....
	//ptr=shmat(shmid,0,SHM_RDONLY);

	/*
	 *(ptr+0)='H';
	*(ptr+1)='E';
	*(ptr+2)='L';
	*(ptr+3)='L';
	*(ptr+4)='0';
	*(ptr+5)=' ';
	*(ptr+6)='H';
	*(ptr+7)='I';
	*(ptr+8)='\0';*/
//strcpy(ptr,"HELLO SASKEN"); here we can overwitte so shm2 get overwritten statement...
strcpy(ptr,"hello Anita");
shmdt(ptr);

}
