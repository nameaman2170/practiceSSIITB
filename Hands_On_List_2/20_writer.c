/*
* Name : 20_writer.c
* Author : Aman Pandey
* Description : Write two programs so that both can communicate by FIFO -Use one way communication
* Date: 9th Aug, 2023
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd = open("fifoFile20", O_WRONLY);
	if(fd == -1){
		printf("An error has occured while opening the file:\n");
		exit(1);
	}
	char *buf = "This is content of fifo file";
	int fd1 = write(fd, buf, strlen(buf));
	if(fd1 == -1){
		printf("Unabke to write in the fifo file\n");
		exit(1);
	}
	close(fd1);
	close(fd);
}
