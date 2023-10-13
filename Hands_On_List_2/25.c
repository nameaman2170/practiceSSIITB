/*
* Name : 24.c
* Author : Aman Pandey
* Description : Write a program to print a message queue's (use `msqid_ds` and `ipc_perm` structures)
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
    // Declarations
    key_t queueKey;
    int queueIdentifier;
    struct msqid_ds messageQueueInfo;
    int msgctlStatus;

    // Compute key using ftok
    queueKey = ftok(".", 1);
    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    // Create message queue or get the identifier if already exists
    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    // Print queue information
    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    // Get message queue information
    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    // Print message queue information
    printf("Access Permission: %od\n", messageQueueInfo.msg_perm.mode);
    printf("UID: %d\n", messageQueueInfo.msg_perm.uid);
    printf("GID: %d\n", messageQueueInfo.msg_perm.gid);
    printf("Time of last message sent: %ld\n", messageQueueInfo.msg_stime);
    printf("Time of last message received: %ld\n", messageQueueInfo.msg_rtime);
    printf("Size of queue: %ld\n", messageQueueInfo.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", messageQueueInfo.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", messageQueueInfo.msg_qbytes);
    printf("PID of last sent message: %d\n", messageQueueInfo.msg_lspid);
    printf("PID of last received message: %d\n", messageQueueInfo.msg_lrpid);
}
