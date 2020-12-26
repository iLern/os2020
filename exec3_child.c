//exec3_child.c
#include <stdio.h>
#include <string.h>
#include "exec3.h"
int main(int argc,char *argv[]){
	int shmid,key;
	char *shmaddr=NULL;
	printf("%s\n",argv[0]);
	key=ftok(PATH_FOR_FTOK,'X');
	shmid=shmget(key,SHM_SIZE,IPC_EXCL);
	shmaddr=(char*)shmat(shmid,NULL,0);
	strcpy(shmaddr,"abcde");
	shmdt(shmaddr);
	V();
	return 0;
}
