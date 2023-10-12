/*
* Name : 16.c
* Author : Aman Pandey
* Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
* Date: 9th Aug, 2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main(){
        int fd[2];
        //Error while creating pipe
        if(pipe(fd) == -1){
                printf("An error has occured while creating the pipe !");
                exit(0);
        }
        int id = fork();

	if(id == -1){
		printf("Error occured while fork!  ");
		exit(1);
	}
//Objective is:
//parent will write a random value and child will read that value and will return the value to parent
//after multiplying by 5
        if(id == 0){
		int x;
                int r = read(fd[0], &x, sizeof(int));
		if(r == -1) exit(1);
		printf("Child has read: %d\n", x);
		x = x*5;
		int w = write(fd[1], &x, sizeof(int));
		if(w == -1) exit(1);
		printf("Child has written: %d\n", x);

        }else{ 
                int x;
		srand(time(NULL));
		int y = rand() % 10;
		write(fd[1], &y, sizeof(int));
		printf("The parent has written: %d\n", y);
		read(fd[0], &y, sizeof(int));
		printf("The new value became: %d\n", y);
        }
        return 0;
}

