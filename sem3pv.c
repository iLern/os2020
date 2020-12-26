//sem3pv.c
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int P(int semid,int semnum){
	struct sembuf sops={semnum,-1,SEM_UNDO};
	return semop(semid,&sops,1);
}

int V(int semid,int semnum){
	struct sembuf sops={semnum,+1,SEM_UNDO};
	return semop(semid,&sops,1);
}



