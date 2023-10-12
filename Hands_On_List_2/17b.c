/*
* Name : 17b.c
* Author : Aman Pandey
* Description : Write a program to execute ls -l | wc.
*               b. use dup2
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
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                execl("/usr/bin/wc", "wc", NULL);
              
        }else{
                close(fd[1]);
                dup2(fd[0], STDIN_FILENO);
                close(fd[0]);
                execl("/usr/bin/ls", "ls","-l", NULL);
          
        }
        return 0;
}

