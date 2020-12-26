//eg4.c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void func(){
	printf("Get alarm\n");
}
int main(){
	int i;
	alarm(3);
	signal(14,func);
	for(i=1;i<=10;i++){
		printf("%d\n",i);
		sleep(1);
		if(i==4)
			alarm(2);
	}

	return 0;
}

