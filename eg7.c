//eg7.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGSIZE 100
struct msgbuf{
	long mtype;
	char mtext[MSGSIZE];
};
int main(){
	int p,key,msqid;
	struct msgbuf msg;
	key=ftok("/boot",'X');
	msqid=msgget(key,IPC_CREAT|0600);
	p=fork();
	if(p){
		// parent
		wait(0);
		msgrcv(msqid,&msg,MSGSIZE,0,0);
		printf("%s\n",msg.mtext);
		msgctl(msqid,IPC_RMID,NULL);
	}else{
		// child
		msg.mtype=1;
		strcpy(msg.mtext,"This is a message");
		msgsnd(msqid,&msg,MSGSIZE,0);
	}
	return 0;
}


