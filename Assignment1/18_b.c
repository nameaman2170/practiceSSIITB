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
#include<string.h>
#include<stdlib.h>
int main(){
        int x;
        int fd = open("file18.txt", O_RDONLY);
        printf("Enter the segment number you want to process 0, 1, 2: ");
        scanf("%d", &x);
	char *str = "this is file line that is used to maintain tthe record\n";
        int size = strlen(str);
        char *buf = (char*)malloc(size);

        struct flock mylock;
        mylock.l_type = F_RDLCK;
        mylock.l_whence = SEEK_SET;
        mylock.l_start = x*size;
        mylock.l_len = size;
        mylock.l_pid = getpid();

        printf("Before entering into lock...\n");
        fcntl(fd, F_SETLKW, &mylock);
        
	printf("entered into lock.... \n");
        
	lseek(fd, mylock.l_start, SEEK_SET);
        
	int fd_read = read(fd, buf, size);
	printf("the fd-read: %d\n", fd_read);
	
	printf("the content of the record is :%s\n", buf);
	printf("enter yo exit: \n");
	
	int b;
	scanf("%d", &b);
        
	printf("exiting the lock....\n");
        
	mylock.l_type = F_UNLCK;
        
	fcntl(fd, F_SETLK, &mylock);
        
	printf("lock released successfully...\n");
        close(fd);
}

