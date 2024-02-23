//..... reanding purpose from msg_Queue............
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
struct mbuf{
	long int mtype;
	char mtext[50];
};
int main(){
//	int key=7766; new key
int key=250;
	int mid;
	struct mbuf msg;//create object;
//	mid=msgget(key,0);// msg queue is not present so return -1 bcc id 7766 not present..
mid=msgget(key,0);
	printf("message queueid:%d\n",mid);
	if(mid!=-1)
	{
//int k=msgrcv(mid,&msg,sizeof(msg),0,IPC_NOWAIT);
//int k=msgrcv(mid,&msg,sizeof(msg),0,0);it will wait...
while(1){
int k=msgrcv(mid,&msg,sizeof(msg),0,IPC_NOWAIT);
if(k==-1){
	perror("");
	printf("We will do something e;lse\n");

	printf("We will do something e;lse\n");
	printf("We will do something e;lse\n");
	sleep(1);
}


//msgrcv(mid,&msg,sizeof(msg),0,0); it will wait to send from mq1.c..
else{
printf("Message type=%ld\n",msg.mtype);
printf("Message text:%s\n",msg.mtext);
break;
}
}
	}//if close...
else{//if msg_queue id not present.....

	printf("NO mesage\n");
	}

}
