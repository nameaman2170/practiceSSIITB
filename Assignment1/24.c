/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(){
	pid_t p = fork();
	if(!p){
		sleep(10);
		printf("%d", getppid());
	}
}
