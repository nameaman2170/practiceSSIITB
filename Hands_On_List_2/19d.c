/*
* Name : 19d.c
* Author : Aman Pandey
* Description : Write a program to create a FIFO file using mknode system call
* Date: 9th Aug, 2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
       	char *filename = "myfifo.txt";
	int x = mknod(filename, S_IFIFO, 0);
	if(x == -1){
		printf("An error occured while creating thr fifo file");
		exit(1);
	}
	printf("fifo file name created successfully!!!");
        return 0;
}

