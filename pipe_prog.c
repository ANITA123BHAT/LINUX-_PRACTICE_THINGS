#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
	FILE *rd;
	char buffer[50];
	sprintf(buffer,"name here first");
	//wc -c means count the number of character in string and -w means no of words in the string.
	rd=popen("wc -w","w");// sending an data from this process to another bcz open a file in write mode
	//wc -c here wc will recieve some all characters and to send data 'w'
	//popen() return file stream
	//fwrite() what you want to send 1st parameter
	//2nd how you want to send= each char by char
	//3rd how much you want to send=length of the string
	//4th where to send in file stream rd.
	//
	fwrite(buffer,sizeof(char),strlen(buffer),rd);
	pclose(rd);
}
