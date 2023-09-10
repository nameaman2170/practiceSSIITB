/*
 Date: 10-sep-2023
 MT2023171
 Aman Pandey
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc, char *argv[]){
	/*S_ISREG(m)  is it a regular file?
         S_ISDIR(m)  directory?

           S_ISCHR(m)  character device?

           S_ISBLK(m)  block device?

           S_ISFIFO(m) FIFO (named pipe)?

           S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

           S_ISSOCK(m) socket?
	   */
	struct stat fileinfo;
	int x = stat(argv[1], &fileinfo);
	if(S_ISREG(fileinfo.st_mode)){
		printf("Reg fille \n");
	}else if(S_ISDIR(fileinfo.st_mode)){
                printf("DIRectory fille \n");
        }else if(S_ISCHR(fileinfo.st_mode)){
                printf("charecter file fille \n");
        }else if(S_ISBLK(fileinfo.st_mode)){
                printf("block fille \n");
        }else if(S_ISFIFO(fileinfo.st_mode)){
                printf("Fifo fille \n");
        }else if(S_ISLNK(fileinfo.st_mode)){
                printf("link fille \n");
        }else if(S_ISSOCK(fileinfo.st_mode)){
                printf("socket fille \n");
        }
	return 0;
}
