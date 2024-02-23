#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){
printf("number of args:%d\n",argc);
for(int i=0;i<argc;i++){
	printf("argv[%d]=%s\n",i,argv[i]);

}

}
