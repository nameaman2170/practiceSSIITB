/*
* Name : 20_reader.c
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
        int fd = open("fifoFile20", O_RDONLY);
        if(fd == -1){
                printf("An error has occured while opening the file:\n");
                exit(1);
        }
        char buf[100];
        int fd1 = read(fd, buf, sizeof(buf));
        if(fd1 == -1){
                printf("Unable to read in the fifo file\n");
                exit(1);
        }
	printf("The reader hsa read: %s\n", buf);
        close(fd1);
        close(fd);
}

