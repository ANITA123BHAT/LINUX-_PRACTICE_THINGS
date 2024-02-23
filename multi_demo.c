#include<stdio.h>
#include<unistd.h>
#define MAX_PROC 3
int main(){
	int A[MAX_PROC];
	for(int i=0;i<MAX_PROC;i++){
		A[i]=fork();
		if(A[i]==0){
			printf("child process id:%d\n",getpid());
			printf("parent process id:%d\n",getppid());
			break;
		}
		
	}
	while(1);

}
