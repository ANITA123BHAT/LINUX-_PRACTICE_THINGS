#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int o_fd;
	int i;
	if(o_fd=open("f100",O_WRONLY|O_CREAT,0777)!=0)
			{
				printf("INSIIDE THE FILE WHICH IS CREATED\n");
                           printf("hello..\n");
			   i=fork();
			   if(i==0){
                            printf("after fork() creation...\n");
			   }
			   else{
				   printf("only parent creation.\n");
			   }

			}
}
