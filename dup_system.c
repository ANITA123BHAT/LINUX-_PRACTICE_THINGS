#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main(){
	int fd;
	fd=open("seeking",O_RDONLY);
	printf("\nOLD file descriptor:%d\n",fd);
	int fd1;
	//fd1=dup(fd);
	//to pass my own value use dup2();
	fd1=dup2(fd,7);

	// dup() system call duplicate the file descriptor...
	// dup2() system call assign  the user required fd value...
	printf("\n new file desciptor:%d\n",fd1);
}
