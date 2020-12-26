//eg6.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024
int main(){
	int shmid,p,key;
	char *shmaddr=NULL;
	key=ftok("./",1711);
	shmid=shmget(key,SIZE,IPC_CREAT | 0600);
	p=fork();
	if(p){
		// parent
		wait(0);
		shmaddr=(char*)shmat(shmid,NULL,0);
		printf("%s\n",shmaddr);
		shmdt(shmaddr);
		shmctl(shmid,IPC_RMID,NULL);
	}else{
		// child
		shmaddr=(char*)shmat(shmid,NULL,0);
		strcpy(shmaddr,"This is a message");
		shmdt(shmaddr);
	}
	return 0;
}


