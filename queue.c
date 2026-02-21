#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"

// Initialization of the empty queue
void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

// Checking if queue is empty
int isEmpty(Queue* q) {
    return (q->head == NULL);
}

// Enqueue a user 
int enqueue(Queue* q, User user) {
    // Allocation of memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
        return 1;  //  failed memory allocation 

    // Setting the  data
    newNode->data = user;
    newNode->next = NULL;

    // Updating the head and tail
    if (isEmpty(q)) {
        q->head = newNode;
        q->tail = newNode;
    }
    else {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    return 0; 
}

// Dequeueing a user from the queue
int dequeue(Queue* q, User* removedUser) {
    if (isEmpty(q))
        return 1; // queue is empty

    // Keeping  track of the first node
    Node* temp = q->head;

    // Copying the data
    *removedUser = temp->data;

    // Moving the head pointer
    q->head = temp->next;

    //  updating the tail ,If  the queue is empty
    if (q->head == NULL)
        q->tail = NULL;

    // Free memory
    free(temp);

    return 0; 
}

// Enqueuing the  multiple randomly generated users
int enqueueRandomUsers(Queue* q, int count) {
    for (int i = 0; i < count; i++) {
        User u;

        //  Generating random usernames (10 chars letters/numbers)
        for (int j = 0; j < 10; j++) {
            int r = rand() % 36;
            if (r < 26)
                u.username[j] = 'a' + r;
            else
                u.username[j] = '0' + (r - 26);
        }
        u.username[10] = '\0'; // terminating the string

        // Generating the random levels 1-60
        u.level = rand() % 60 + 1;

        // Generating the random factions
        int f = rand() % 3;
        if (f == 0)
            strcpy(u.faction, "red");
        else if (f == 1)
            strcpy(u.faction, "blue");
        else
            strcpy(u.faction, "green");

        // Adding users to queue
        if (enqueue(q, u) != 0)
            return 1; // error in  adding the  user
    }

    return 0; 
}