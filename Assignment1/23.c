/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(){
	int p = fork();
	printf("the parent is : %d\n", getpid());
	if(!p){
		printf("child PID: %d\n", getpid());
		exit(0);
	}else if(p != -1){
		sleep(10);
		//wait(NULL);
	}
	//run the process in background
	//run ps command in the same terminal
	return 0;
}
