#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
	printf("Before\n");
	execl("/bin/ps","ps","-1",NULL);
	printf("After\n");

}
