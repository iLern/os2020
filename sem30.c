//sem30.c
#include "sem3.h"

int main(int argc,char* argv[]){
	int semid,shm1id,shm2id,semkey,shm1key,shm2key;
	int p1,p2,p3;
	union semun arg;
	semkey =ftok(FILE_FOR_FTOK,'X');
	shm1key=ftok(FILE_FOR_FTOK,'Y');
	shm2key=ftok(FILE_FOR_FTOK,'Z');
	semid =semget(semkey ,4,IPC_CREAT | 0600);
	shm1id=shmget(shm1key,SHM_SIZE,IPC_CREAT | 0600);
	shm2id=shmget(shm2key,SHM_SIZE,IPC_CREAT | 0600);
	arg.array=(unsigned short*)malloc(sizeof(unsigned short)*4);
	arg.array[0]=1;
	arg.array[1]=0;
	arg.array[2]=1;
	arg.array[3]=0;
	semctl(semid,0,SETALL,arg);
	p1=fork();
	if(p1){
		p2=fork();
		if(p2){
			p3=fork();
			if(p3){
				waitpid(p1,NULL,0);
				waitpid(p2,NULL,0);
				waitpid(p3,NULL,0);
				semctl(semid,0,IPC_RMID);
				shmctl(shm1id,IPC_RMID,NULL);
				shmctl(shm2id,IPC_RMID,NULL);
				free(arg.array);
				printf("\n");
			}else{
				// child 3
				execl("./sem33",argv[1],NULL);
			}
		}else{
			// child 2
			execl("./sem32",argv[1],NULL);
		}
	}else{
		// child 1
		execl("./sem31",argv[1],NULL);
	}
	return 0;
}


