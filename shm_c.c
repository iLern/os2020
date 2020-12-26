//eg6.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024
int main(){
	int key=ftok("./shm_c",'X');
	shmget(key,SIZE,IPC_CREAT | 0666);
	return 0;
}


