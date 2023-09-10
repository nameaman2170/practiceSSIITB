/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd = open("file11.txt", O_RDWR | O_CREAT);
	write(fd, "this is the data after just opening\n", 37);
	int fd1 = dup(fd);
	write(fd1, "This is data after 1st duplication\n", 36);
	close(fd);
	int fd2 = dup2(fd1, fd);
	write(fd2, "This is data after 2nd duplication\n", 36);
	write(fd1, "This is second data after 2nd duplication\n", 37);
	lseek(fd1, 0, SEEK_SET);
	close(fd);
	FILE* file = fopen("file11.txt", "r");
	char ch;
	while((ch = getc(file)) != EOF){
		putchar(ch);
	}
	fclose(file);
}
