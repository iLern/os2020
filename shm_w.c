//shm_w.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024
int main(int argc,char *argv[]){
	int shmid,key=ftok("./shm_c",'X');
	char *shmaddr=NULL;
	shmid=shmget(key,SIZE,IPC_EXCL);
	shmaddr=(char*)shmat(shmid,NULL,0);
	strcpy(shmaddr,argv[1]);
	shmdt(shmaddr);
	
	return 0;
}


