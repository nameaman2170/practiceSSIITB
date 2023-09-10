/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
        struct flock mylock;
        mylock.l_type = F_RDLCK;
        mylock.l_whence = SEEK_SET;
        mylock.l_start = 0;
        mylock.l_len = 0;
        mylock.l_pid = getpid();
        int fd = open("ip.txt", O_RDWR);
        printf("Before entering CS: ");
        fcntl(fd, F_SETLKW, &mylock);
        printf("Entered into the critical section :\n ");
        printf("enter to unclock \n");
        getchar();
        mylock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &mylock);
        printf("unlocked \n");
}

