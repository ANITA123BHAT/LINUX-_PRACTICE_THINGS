#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int pd[2],px[2];
	pipe(pd);// call two more descriptor for read and write... 
	pipe(px);
char buf[20]={0};

		char rbuf[20]={0};
	printf("pd[0]=%d\n",pd[0]);
	printf("pd[0]=%d\n",pd[1]);
       printf("px[0]=%d\n",px[0]);
       printf("px[1]=%d\n",px[1]);
      int i=fork();
	if(i==0){
	printf("child process\n");
	read(pd[0],buf,12);
	printf("Read data from parent =%s\n",buf);
	write(px[1],"HELLO PARENT",12);
	printf("child writes\n");
	printf("Child complete\n");
	}
	else{
		printf("parent process\n");
		write(pd[1],"HELLO CHILD",12);
		printf("Parent writes\n");

		read(px[0],rbuf,13);
		printf("reaadr from child:%s\n",rbuf);
		printf("Parent complete\n");
		wait(0);
	}
   while(1);
}
