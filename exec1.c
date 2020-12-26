//exec1.c
#include <stdio.h>
#include <unistd.h>
int main(){
	int x=100;
	char *arg[]={"aaa","bbb",NULL};
	printf("1111:My pid=%d,x=%d\n",getpid(),x);
	execv("./exec2",arg);
	printf("2222\n");
	return 0;
}

