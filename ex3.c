//ex3.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void child_stop(){
	printf("Child process (pid=%d) be killed\n",getpid());
	exit(0);
}
void parent_stop(){
	printf("parent precess (pid=%d) get SIGINT/SIGQUIT\n",getpid());
//	exit(0);
}
int main(){
	int p1,p2;

	p1=fork();
	if(p1){
		// parent
		p2=fork();
		if(p2){
			// parent
			signal(2,parent_stop);
			signal(3,parent_stop);
			sleep(5);
			kill(p1,10);
			kill(p2,12);
			wait(0);
			wait(0);
			printf("Parent process (pid=%d) finished\n",getpid());
		}else{
			// child 2
			signal(12,child_stop);
			sleep(6);
		}
	}else{
		// child 1
		signal(10,child_stop);
		sleep(6);
	}

	return 0;
}

