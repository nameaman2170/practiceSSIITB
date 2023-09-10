/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(){
	int p = getpriority(PRIO_PROCESS, getpid());
	printf("The current priority is: %d\n", p);
	int val = nice(10);
	if(val == -1){
		printf("Error");
		return 1;
	}
	printf("The new priority: %d", getpriority(PRIO_PROCESS, getpid()));
	return 0;
}
