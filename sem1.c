//sem1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
	int val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

void P(int semid,int semnum){
	struct sembuf sops={semnum,-1,SEM_UNDO};
	semop(semid,&sops,1);
}

void V(int semid,int semnum){
	struct sembuf sops={semnum,+1,SEM_UNDO};
	semop(semid,&sops,1);
}

int main(){
	int key,semid;
	union semun arg;
	key=ftok("/boot",'S');
	semid=semget(key,3,IPC_CREAT | 0600);
	arg.val=1;
	semctl(semid,1,SETVAL,arg);
	printf("After setval,sem[1]=%d\n",semctl(semid,1,GETVAL,arg));
	printf("P operate begin at:\n");
	system("date");
	P(semid,1);
	printf("P opertae end at:\n");
	system("date");
	printf("After P operate,sem[1]=%d\n",semctl(semid,1,GETVAL,arg));
	printf("Start sleep 60 seconds,slppeing\n");
	sleep(60);
	printf("V operate begin at:\n");
	system("date");
	V(semid,1);
	printf("V operate end at:\n");
	system("date");

	return 0;
}


