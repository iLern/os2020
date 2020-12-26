//test1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	int p;

	printf("Hello world\n");
	p=fork();
	if(p==-1){
		printf("fork error\n");
		exit(0);
	}
	if(p){
		// parent
		sleep(1);
		printf("This is parent,my pid=%d,my child=%d\n",getpid(),p);
	}else{
		// child
		printf("This is child ,my pid=%d,my parent=%d\n",getpid(),getppid());
	}	
	return 0;
}

/*
	switch(fork()){
		case -1:
			printf("error");
			//exit(0);
			break;
		case 0:
			// child

			break;
		default:
			// parent

			break;
	}
*/		
