/*
* Name : 26.c
* Author : Aman Pandey
* Description : Write a program to send messages to the message queue. Check `ipcs -q`
* Date: 10th Aug, 2023
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>  
#include <unistd.h> 
#include <errno.h>

int main()
{
    key_t queueKey; 
    int queueIdentifier;
    int messageSendStatus;

    struct msgbuf
    {
        long mtype;     // Used to identify message type - should be > 0
        int someNumber; // Integer data
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!");
        _exit(0);
    }

    data.mtype = 1;
    data.someNumber = 100;

    messageSendStatus = msgsnd(queueIdentifier, &data, sizeof(data), 0);

    if (messageSendStatus == -1)
    {
        perror("Error while sending message via Message Queue!");
        _exit(0);
    }

    printf("Message sent! Check using `ipcs -q`\n");
}