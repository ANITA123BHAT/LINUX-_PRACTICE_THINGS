#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	int key=65553;
	int shmid;
	char *ptr;
	shmid=shmget(key,0,0);
	printf("shared memory id:%d\n",shmid);
	ptr=shmat(shmid,0,SHM_RDONLY);//read only mode....

	for(int i=0;*(ptr+i);i++){
		printf("%c",*(ptr+i));
	}
	//printf("%s\n",ptr); or we use this.... to read from shred memory..
	printf("\n");
	shmdt(ptr);
}
