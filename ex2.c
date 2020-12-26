//ex2.c
#include <stdio.h>
#include <unistd.h>
int main(){
	int p1,p2,fda[2],fdb[2];
	char c;
	pipe(fda);
	p1=fork();
	if(p1){
		// parent
		pipe(fdb);
		p2=fork();
		if(p2){
			// parent
			do{
				read(fdb[0],&c,sizeof(char));
				printf("%c",c);
			}while(c!='\n');
			printf("\n");
		}else{
			// child 2
			do{
				read(fda[0],&c,sizeof(char));
				if(c>='a' && c<='z')
					c=c-'a'+'A';
				else
					if(c>='A' && c<='Z')
						c=c-'A'+'a';
				write(fdb[1],&c,sizeof(char));
			}while(c!='\n');
		}
	}else{
		// child 1
		printf("Input string:\n");
		do{
			c=getchar();
			write(fda[1],&c,sizeof(char));	
		}while(c!='\n');	
	}
	return 0;
}
