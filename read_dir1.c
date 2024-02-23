#include<stdio.h>
#include<string.h>
#include<dirent.h>
int main(int argc, char *args[]){
	DIR *myDirectory;
	struct dirent *myFile;
	if(argc==2){
           myDirectory=opendir(args[1]);
	   if(myDirectory)
	   {
		   puts("OK directory is opended lets see its file\n");
		   while((myFile==readdir(myDirectory))){
			   printf("%s\n",myFile->d_name);
			   if(myFile->d_type==DT_REG){
				   printf("f ");
			   }
			   else if(myFile->d_type==DT_DIR){
				   printf("d ");
			   }
			   if(myFile->d_type==DT_LNK){
				   printf("l");
			   }
			   if(myFile->d_type==DT_FIFO){
				   printf("p");
			   }
			   printf("%ld\n",myFile->d_ino);
		   }
	   }
	}
}
