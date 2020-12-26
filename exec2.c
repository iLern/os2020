//exec2.c
#include <stdio.h>
//#include <unistd.h>
int main(int argc,char *argv[]){
	int x=200;
	printf("3333:My pid=%d,x=%d\n",getpid(),x);
	printf("argv[0]=%s,argv[1]=%s,argv[2]=%s\n",argv[0],argv[1],argv[2]);
	return 0;
}

