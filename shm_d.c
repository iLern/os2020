//shm_d.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024
int main(){
	int shmid,key=ftok("./shm_c",'X');
	shmid=shmget(key,SIZE,IPC_EXCL);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}


