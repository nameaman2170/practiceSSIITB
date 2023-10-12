/*
* Name : 17c.c
* Author : Aman Pandey
* Description : Write a program to execute ls -l | wc.
*               c. use fcntl
* Date: 9th Aug, 2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){
        int fd[2];
        //Error while creating pipe
        if(pipe(fd) == -1){
                printf("An error has occured while creating the pipe !");
                exit(0);
        }
	fcntl(fd[1], F_SETFL, O_NONBLOCK);

        int id = fork();
	//word count
        if(id == 0){
        	close(fd[1]);
		char buf[100];
		int d;
		while((d = read(fd[0], buf, sizeof(buf))) > 0){
			write(STDOUT_FILENO, buf, d);
		}	
		close(fd[0]);
        }else{ //ls -l
		close(fd[0]);
		close(STDOUT_FILENO);
		fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
		close(fd[1]);
		execl("/usr/bin/ls", "ls", "-l", NULL);
        }
        return 0;
}

