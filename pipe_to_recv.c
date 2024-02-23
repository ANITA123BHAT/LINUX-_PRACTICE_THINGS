#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
	//program to receive data from another..
	//since i wnat receive what so make sure whatever 1st you pass it to pipe that should read data from another . here ls prints the list of directory contents. 
	//where wc process which needs some data to give it
	//2nd para is 'r' to read data
	//to read data from other we use fread or to send fwrite
	//rd is name of the file stream
	//write system call to print on screen
	 
FILE *rd;
char buffer[50];
rd=popen("ls","r");
fread(buffer,sizeof(char),20,rd);//20 is how much we need to red..
write(1,buffer,20);
printf("\n");
pclose(rd);
}
