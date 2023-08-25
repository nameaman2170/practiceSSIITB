#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
int main(){
	struct timeval time;
	time.tv_sec = 10;	
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);
	int res = select(STDIN_FILENO+1, &readfds, NULL, NULL, &time);
	if(res == -1){
		printf("not able to run: ");
	}else if(res == 0){
		printf("the data is not available: ");
	}else{
		printf("Data is available : ");
	}
	return 0;
}
