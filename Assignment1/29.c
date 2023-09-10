/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sched.h>

int main(){
	int pid = getpid();
	int policy = sched_getscheduler(pid);
	struct sched_param p;
	p.sched_priority = 10;
	printf("SCHED_FIFO: %d\n", SCHED_FIFO);
	printf("SCHED_RR: %d\n", SCHED_RR);
	printf("%d\n", policy);
	if(policy == SCHED_FIFO){
		printf("The policy is FIFO\n");
		policy = sched_setscheduler(pid, SCHED_RR, &p);
		printf("Now the policy is = %d\n", policy);
	}else if(policy == SCHED_RR){
		printf("the policy is RR\n");
		policy = sched_setscheduler(pid, SCHED_FIFO, &p);
		printf("now the policy is = %d\n", policy);
	}
}

