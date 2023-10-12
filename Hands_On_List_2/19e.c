/*
* Name : 19e.c
* Author : Aman Pandey
* Description : Write a program to create a FIFO file using mkfifo system call
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
        char *filename = "fifoFile21";
        int x = mkfifo(filename, 0777);
        if(x == -1){
                printf("An error occured while creating thr fifo file");
                exit(1);
        }
        printf("fifo file name created successfully!!!");
        return 0;
}

