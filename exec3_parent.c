//exec3_parent.c
#include <stdio.h>
#include "exec3.h"
int main(int argc,char *argv[]){
	int shmid,key;
	char *shmaddr=NULL;
	printf("%s\n",argv[0]);
	key=ftok(PATH_FOR_FTOK,'X');
	shmid=shmget(key,SHM_SIZE,IPC_EXCL);
	P();
	shmaddr=(char*)shmat(shmid,NULL,0);
	printf("%s\n",shmaddr);
	shmdt(shmaddr);
	shmctl(shmid,IPC_RMID,NULL);
	semctl(,,IPC_RMID,);
	return 0;
}
