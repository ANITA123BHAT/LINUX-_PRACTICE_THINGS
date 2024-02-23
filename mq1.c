#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

struct msgbuf{//to write into a msg Queue..
	long int msgtype;
	char msgtext[50];
};
int main(){
//	int key=255;//project id....
int key=250;
	int mq_id;//msg queue id....
	struct msgbuf m;//struct variable..
//	mq_id=msgget(key,0);  if not present -0 indicate..
mq_id=msgget(key,IPC_CREAT|0777);// if not present create it and return msg queue id..
	printf("Message Queue Id=%d\n",mq_id);
	m.msgtype=1234;
strcpy(m.msgtext,"HELLO SASKEN BANGALORE");
	msgsnd(mq_id,&m,sizeof(m),0);// flag-0  for wait for msg queue if it is ffull
printf("message1 sent\n");

m.msgtype=2244;
strcpy(m.msgtext,"hello india");

	msgsnd(mq_id,&m,sizeof(m),0);// flag-0  for wait for msg queue if it is ffull

printf("message2 sent\n");

}


