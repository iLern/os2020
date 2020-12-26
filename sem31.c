//sem31.c
#include "sem3.h"
int main(int argc,char* argv[]){
	int semkey,shm1key,semid,shm1id,i,seed;
	char c,*shm1addr=NULL;
	semkey=ftok(FILE_FOR_FTOK,'X');
	shm1key=ftok(FILE_FOR_FTOK,'Y');
	semid=semget(semkey,0,IPC_EXCL);
	shm1id=shmget(shm1key,SHM_SIZE,IPC_EXCL);
	seed=getpid();
	for(i=1;i<=atoi(argv[0]);i++){
		do{
			c=(char)(rand_r(&seed)%128);
		}while(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')));
		printf("Random letter is %c\n",c);
		P(semid,0);
		shm1addr=(char*)shmat(shm1id,NULL,0);
		shm1addr[0]=c;
		shmdt(shm1addr);
		V(semid,0);
		V(semid,1);
		sleep(rand_r(&seed)%5+1);
	}
	return 0;
}


