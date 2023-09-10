/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
int main(){
	int fd = open("ip.txt", O_RDWR);
	char str[10] = "0123456789";
	write(fd, &str, 10);
	if(fd_write == -1){
		printf("not able to write the code: ");
	} 
	off_t seek_var = lseek(fd, 10, SEEK_CUR);
	write(fd, &str, 10);
	close(fd);
	return 0;	
}
