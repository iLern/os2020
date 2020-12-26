//eg2.c
#include <stdio.h>
#include <unistd.h>
int main(){
	int p;
	p=fork();
	if(p){
		// parent
		printf("This is parent,my pid=%d,my child=%d,my parent=%d\n",getpid(),p,getppid());
	}else{
		// child
		sleep(3);
		printf("This is child,pid=%d,parent=%d\n",getpid(),getppid());
	}

	return 0;
}


