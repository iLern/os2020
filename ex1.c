//ex1.c
#include <stdio.h>
#include <unistd.h>
int main(){
	int p1,p2,i;
	p1=fork();
	if(p1){
		// parent
		p2=fork();
		if(p2){
			// parent
			for(i=1;i<=6;i++){
				printf("%d",i);
				fflush(stdout);
				sleep(1);
			}
			printf("\n");
		}else{
			// child 2
			for(i='a';i<='f';i++){
				printf("%c",i);
				fflush(stdout);
				sleep(1);
			}
		}
	}else{
		// child 1
		for(i='A';i<='F';i++){
			printf("%c",i);
			fflush(stdout);
			sleep(1);
		}
	}
	return 0;
}
