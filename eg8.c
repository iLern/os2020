//eg8.c
int main(){
	int p1,p2,semid,sem_key,shm1_key,shm2_key;
	sem_key =ftok("/boot",'X');
	shm1_key=ftok("/boot",'Y');
	shm2_key=ftok("/boot",'Z');
	semid=semget(key,4,0);
	p1=fork();
	if(p1){
		p2=fork();
		if(p2){
			execl("./output","./output",NULL);		
		}else{
			execl("./process","./process",NULL);
		}
	}else{
		execl("./input","./input",NULL);
	}
	return 0;
}

