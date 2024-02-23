#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int i=fork();
	if(i>0){
		printf("parent process..\n");
	}
	else{
            sleep(20);
	    printf("child process\n");
	}
	return 0;
}
