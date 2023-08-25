#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd = open("ticket_file.txt", O_CREAT|O_RDWR);
	int buf  = 1;
	write(fd, &buf, sizeof(buf));
	close(fd);
}

