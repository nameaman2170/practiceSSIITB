/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd = open("file18.txt",O_RDWR | O_CREAT);
	char *buf = "this is file line that is used to maintain tthe record\n";
	int size = strlen(buf);
	write(fd, buf, size);
	write(fd, buf, size);
	write(fd, buf, size);
	close(fd);
}
