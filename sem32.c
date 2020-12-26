//sem32.c
#include "sem3.h"
int main(int argc,char* argv[]){
	int semkey,shm1key,shm2key,semid,shm1id,shm2id,i;
	char c,*shm1addr=NULL,*shm2addr=NULL;
	semkey =ftok(FILE_FOR_FTOK,'X');
	shm1key=ftok(FILE_FOR_FTOK,'Y');
	shm2key=ftok(FILE_FOR_FTOK,'Z');
	semid =semget(semkey ,0,IPC_EXCL);
	shm1id=shmget(shm1key,0,IPC_EXCL);
	shm2id=shmget(shm2key,0,IPC_EXCL);
	for(i=1;i<=atoi(argv[0]);i++){
		P(semid,1);
		P(semid,0);
		shm1addr=(char*)shmat(shm1id,NULL,0);
		c=shm1addr[0];
		shmdt(shm1addr);
		V(semid,0);
		if(c>='a'&c<='z')
			c=c-'a'+'A';
		else
			c=c-'A'+'a';
		P(semid,2);
		shm2addr=(char*)shmat(shm2id,NULL,0);
		shm2addr[0]=c;
		shmdt(shm2addr);
		V(semid,2);
		V(semid,3);
	}
	return 0;
}
