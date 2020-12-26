//msg_r.c
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
	int p,key,msqid;
	struct msgbuf msg;
	key=ftok("/boot",'X');
	msqid=msgget(key,IPC_EXCL);
	msgrcv(msqid,&msg,MSGSIZE,atoi(argv[1]),0);
	printf("%s\n",msg.mtext);
	return 0;
}


