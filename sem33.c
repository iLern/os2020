//sem33.c
#include "sem3.h"
int main(int argc,char* argv[]){
	int semkey,shm2key,semid,shm2id,i;
	char c,*shm2addr=NULL;
	semkey =ftok(FILE_FOR_FTOK,'X');
	shm2key=ftok(FILE_FOR_FTOK,'Z');
	semid =semget(semkey ,0,IPC_EXCL);
	shm2id=shmget(shm2key,0,IPC_EXCL);
	for(i=1;i<=atoi(argv[0]);i++){
		P(semid,3);
		P(semid,2);
		shm2addr=(char*)shmat(shm2id,NULL,0);
		printf("After transform :%c\n",shm2addr[0]);
		shmdt(shm2addr);
		V(semid,2);
	}
	return 0;
}
