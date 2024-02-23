//client 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	int sockfd,portno,n;
	struct sockaddr_in serv_addr;

	char buffer[1024];
	//check for appropriate no .of command line inputs..
	if(argc<3){
		printf("provide required command lin input as<filename.c><server_IP_addr><portno>\n");
		exit(1);
	}

	portno=atoi(argv[2]);
	sockfd=socket(AF_INET,SOCK_STREAM,0);

	//check if socket is created properly
	if(sockfd<0){
		printf("error i opening socket\n");
		exit(1);
	}

	//build the structure for server address
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(portno);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
//speciefing address of server i.e inet_addr
	//now try to connect with the server...
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0){
		printf("Connection failed...!!\n");
		exit(1);
		}
		while(1){
		bzero(buffer,1024);//clear buffer
	
		//now write some data to the servre..
		fgets(buffer,1024,stdin);
		n=write(sockfd,buffer,strlen(buffer));
		if(n<0){
			printf("errror in writing ...\n");
			exit(1);
		}

		//now read back from the server...
		bzero(buffer,1024);
		//clear buffer
		n=read(sockfd,buffer,1024);
		if(n<0){
			printf("\n error in reading..\n");
			exit(1);
		}
		//print server's response...
		printf("\nserver--->%s\n",buffer);

		//detect end of conversation...
		if(!strncmp("bye",buffer,3)){
			break;
		}

	}
	close(sockfd);
	return 0;
}
