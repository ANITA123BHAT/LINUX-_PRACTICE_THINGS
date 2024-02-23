#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int i,j,k;
	i=fork();
	if(i==0){
		printf("first child");
	}
	else{
          j=fork();
	  if(j==0){
		  printf("second child");
	  }
	  else{

		  k=fork();
		  if(k==0){
			  printf("third child");
		  }
		  else{
			  wait(0);
			  wait(0);
			  wait(0);
		  }
	  }

	}
}
