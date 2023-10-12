/*
* Name : 15.c
* Author : Aman Pandey
* Description : Write a simple program to send some data from parent to the child process.
* Date: 9th Aug, 2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
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
                close(fd[1]);
                char buf[100];
		read(fd[0], buf, sizeof(buf));
		printf("Reading from child: %s", buf);
                close(fd[0]);
        }else{ //parent process to read
                close(fd[0]);
             	char msg[] = "hii this is parent message";
		write(fd[1], &msg, strlen(msg));
                close(fd[1]);
        }
        return 0;
}
