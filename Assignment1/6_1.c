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
	char buf[100];
	read(0, &buf, 100);
	write(1, &buf, 100);
}
