//msg_s.c
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
int main(int argc,char *argv[]){
	int p,key,msqid,i;
	struct msgbuf msg;
	key=ftok("/boot",'X');
	msqid=msgget(key,IPC_EXCL);
//	for(i=1;i<=8;i++){
		msg.mtype=atoi(argv[1]);
		strcpy(msg.mtext,argv[2]);
//		msg.mtext[strlen(msg.mtext)+1]='\0';
//		msg.mtext[strlen(msg.mtext)]=i+'0';
		msgsnd(msqid,&msg,MSGSIZE,0);
//	}
	return 0;
}


