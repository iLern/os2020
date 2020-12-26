//msg_c.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(){
	int key;
	key=ftok("/boot",'X');
	msgget(key,IPC_CREAT|0600);
	return 0;
}


