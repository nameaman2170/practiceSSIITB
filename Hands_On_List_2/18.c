/*
* Name : 18.c
* Author : Aman Pandey
* Description : Write a program to find out total number of directories on the pwd.
*		execute ls -l | grep ^d | wc ? Use only dup2
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

        if(id == 0){
                close(fd[0]);
                close(STDOUT_FILENO);
                dup(fd[1]);
                close(fd[1]);
                execl("/usr/bin/wc", "wc", NULL);
                exit(1);
        }else{
                close(fd[1]);
                close(STDIN_FILENO);
                dup(fd[0]);
                close(fd[0]);
                execl("/usr/bin/ls", "ls","-l", NULL);
                exit(1);
        }
        return 0;
}

