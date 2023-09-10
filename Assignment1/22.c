/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("file22.txt", O_CREAT | O_RDWR);
	char *str1 = "this is written by parent\n";
	char *str2 = "this is written by child\n";
	if(!fork()){
		write(fd, str2, strlen(str2));
		lseek(fd, strlen(str2), SEEK_SET);
	}else{
		write(fd, str1, strlen(str1));
		lseek(fd, strlen(str1), SEEK_SET);
	}
	return 0;
}
