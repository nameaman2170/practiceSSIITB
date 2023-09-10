/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t p1, p2, p3, wfc;
	int ws;
	if((p1 = fork()) == 0){
		sleep(5);
		exit(0);
	}else{
		if((p2 = fork()) == 0){
			sleep(10);
			exit(0);
		}else{
			if((p3 = fork()) == 0){
				sleep(15);
			}else{
				wfc = waitpid(p3, &ws, 0);
				if(wfc == p3){
					if(ws== 0)
						printf("exited with wait status = 0\n");
					else
						printf("exited with wait stats = %d\n", ws);
				}		
			}
		}
	}
}
