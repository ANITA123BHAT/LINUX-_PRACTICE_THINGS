#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int i;
	i=fork();
	if(i>0){
		sleep(15);
	printf("hello\n");
	}
	else{
	//	sleep(1000);
	//	printf("hello...\n");
	exit(0);
	}

	

}
