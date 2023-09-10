/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int fd = open("file18.txt", O_RDONLY);
	int x = fcntl(fd, F_GETFL);
	printf("readmode = %d\n", O_RDONLY);
	printf("write mode = %d\n", O_WRONLY);
	printf("read write mode is = %d\n", O_RDWR);
	printf("The mode is : %d \n", x);
}
