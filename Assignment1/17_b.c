#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int fd = open("ticket_file.txt", O_RDWR);
	struct flock mylock;
        mylock.l_type = F_WRLCK;
        mylock.l_whence = SEEK_SET;
        mylock.l_start = 0;
        mylock.l_len = 0;
        mylock.l_pid = getpid();
        printf("Before entering CS: ");
	//acquire the lock 
        fcntl(fd, F_SETLKW, &mylock);
        printf("Entered into the critical section :\n ");
        printf("enter to unlock \n");
	getchar();
	//read the file data
	int buf;
	read(fd, &buf, sizeof(buf));
	printf("The current ticket number is: %d\n", buf);
	buf = buf+1;
	lseek(fd, 0, SEEK_SET);
	printf("Now ticket number is: %d\n", buf);
	write(fd, &buf, sizeof(buf));
        mylock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &mylock);
        printf("unlocked \n"); 
}
