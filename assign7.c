#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include<sys/ipc.h>
struct msgbuf{
	long int msgtype;
	char msgtext[50];
};
int main(){
long	int key=212766;
	int msg_id1;
struct msgbuf m1;
	msg_id1=msgget(key,IPC_CREAT|0777);
	printf("MESSAGE QUEUE ID:%d\n",msg_id1);
	int num=3;
	do
	{

	printf("the message you wnat to send\n");
printf("1:RED\n");
printf("2:YELLOW\n");
printf("3:GREEN\n");
printf("Other numer to exit from sending.\n");
		scanf("%d",&num);
	switch(num){
		case 1:{
	m1.msgtype=12345;
	strcpy(m1.msgtext,"RED");
	msgsnd(msg_id1,&m1,sizeof(m1),0);
          printf("message 1 sent..\n");
		       }
		       break;
		case 2:{
	m1.msgtype=212767;
	strcpy(m1.msgtext,"YELLOW");
msgsnd(msg_id1,&m1,sizeof(m1),0);
printf("messasge2 sent\n");
		       }
		       break;
		case 3:{

m1.msgtype=212768;
strcpy(m1.msgtext,"GREEN");
msgsnd(msg_id1,&m1,sizeof(m1),0);
printf("message3 sent...\n");
		       }
		       break;
	}
	}while(num<4);
}
