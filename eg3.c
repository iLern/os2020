//eg3.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define SIZE 50
int main(){
	int fd[2],p;
	char s[SIZE];
	pipe(fd);
	p=fork();
	if(p){
		//parent
		wait(0);
//		waitpid(p,NULL,0);
		printf("%s\n",s);
		read(fd[0],s,SIZE);
		printf("%s\n",s);
	}else{
		//child
		strcpy(s,"Hello");
		write(fd[1],s,SIZE);
	}

	return 0;
}
