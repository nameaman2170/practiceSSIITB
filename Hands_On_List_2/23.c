/*
* Name : 23.c
* Author : Aman Pandey
* Description : Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
* Date: 10th Aug, 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main() {
    long max_files = sysconf(_SC_OPEN_MAX);
    printf("max opened files count: %ld\n", max_files);
    long pipe_buf_size = PIPE_BUF;

    printf("circular buffer: %ld bytes\n", pipe_buf_size);

    return 0;
}
