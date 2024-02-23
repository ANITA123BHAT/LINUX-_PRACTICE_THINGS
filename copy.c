#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int src_fd,dst_fd;
	char ch;
	if((src_fd=open("f1",O_RDONLY))!=-1){
		dst_fd=open("new2",O_WRONLY|O_CREAT,0660);
		while(read(src_fd,&ch,1)){
                   write(dst_fd,&ch,1);//1 is no of character.. 

		}
		close(src_fd);
		close(dst_fd);
	}
	else{
		perror("");
	}
}
//copy one file to another file....
