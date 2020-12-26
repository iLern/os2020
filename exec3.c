//exec3.c
#include <stdio.h>
#include "exec3.h"
int main(){
	int p;
	char *arg[]={"I am child",NULL};
	int key=ftok(PATH_FOR_FTOK,'X');
	shmget(key,SHM_SIZE,IPC_CREAT | 0600);
	semget();
	semcetl(,,SETVAL,);
	p=fork();
	if(p){
//		wait(0);
		execl("./exec3_parent","I am parent",NULL);
	}else{
		execv("./exec3_child",arg);
	}
	return 0;
}
