/*
* Name : 21_writer.c
* Author : Aman Pandey
* Description : Write two programs so that both can communicate by FIFO -Use two way communication
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
        int fd = open("fifoFile21", O_RDWR);
        if(fd == -1){
                printf("An error has occured while opening the file:\n");
                exit(1);
        }
        char *buf = "Hello  this is message from the 21th writer file!!";
        int fd1 = write(fd, buf, strlen(buf));
        if(fd1 == -1){
                printf("Unable to write in the fifo file\n");
                exit(1);
        }
	fd = open("fifoFile21", O_RDONLY);
	char buf1[100];
	int d = read(fd, buf1, sizeof(buf1));
	buf1[d] = '\0';
	printf("The file content read by 21th writer is: %s\n", buf1);
        close(fd1);
        close(fd);
}

