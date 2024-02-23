#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
	int res,n;
	res=open("fifo1",O_NONBLOCK|O_WRONLY);//we have opened the fifo1 file i.e named file
	// here sending a msg to "Message" to named pipe fifo1
	write(res,"Message",7);
	printf("sender process having PID%d sent the data\n",getpid());
// here O_NONBLOCK is to not to  wait for send/recv for any other process.
}
