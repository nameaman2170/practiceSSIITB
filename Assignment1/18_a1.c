/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	int x;
	int fd = open("file18.txt", O_RDWR);
	printf("Enter the segment number you want to process 0, 1, 2: ");
	scanf("%d", &x);
	int size = 100;
	char *buf;

	struct flock mylock;
        mylock.l_type = F_WRLCK;
     	mylock.l_whence = SEEK_SET;
	mylock.l_start = x*size;
        mylock.l_len = size;
        mylock.l_pid = getpid();
	printf("Before entering into lock...");
	fcntl(fd, F_SETLKW, &mylock);
	printf("entered into lock.... ");
	lseek(fd, mylock.l_start, SEEK_SET);
	printf("enter to exit from lock..");
	scanf("%s", buf);
	write(fd, &buf, size);
	printf("exiting the lock....");
	mylock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &mylock);
	printf("lock released successfully...");
	close(fd);
}
