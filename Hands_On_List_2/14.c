/*
Name : 14.c
Author : Aman Pandey

Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

Date: 9th Aug, 2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int fd[2];
	//Error while creating pipe
	if(pipe(fd) == -1){
		printf("An error has occured while creating the pipe !");
		exit(0);
	}
	int id = fork();

	//child process to write
	if(id == 0){
		close(fd[0]);
		int x;
		printf("Enter the number to write: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}else{ //parent process to read
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("got from child! %d", y);
	}
	return 0;
}
