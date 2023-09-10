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

int main(){
	if(!fork()){
		printf("this is the child: %d\n", getpid());
	}else{
		printf("This is the parent: %d\n", getpid());
	}

	return 0;
}
