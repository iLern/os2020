//eg4.c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void func(){
	printf("Get alarm\n");
}
int main(){
	int p;
	signal(10,func);
	p=fork();
	if(p){
		// parent
		sleep(2);
		kill(p,10);
		wait(0);
	}else{
		// child
		sleep(5);
//		kill(getpid(),9);
//		exit(0);
	}
	return 0;
}

