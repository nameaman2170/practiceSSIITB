/*
* Name : 22.c
* Author : Aman Pandey
* Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO
* Date: 9th Aug, 2023
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main(){
        struct timeval timeout;
        int fd;
        fd_set fds;
        mkfifo("fifoFile22", 0666);
        fd = open("fifoFile22", O_RDONLY);

        FD_ZERO(&fds);
        FD_SET(fd, &fds);
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        printf("Waiting for date in FIFO: \n");
        int sr = select(fd+1, &fds, NULL, NULL, &timeout);
        if(sr == 0){
                printf("No data is available: \n");
        }else{
                if(FD_ISSET(fd, &fds)){
                        char buf[100];
                        int d = read(fd, buf, sizeof(buf));
                        printf("The data read by reader is : %s\n", buf);
                }
        }
        close(fd);
}

