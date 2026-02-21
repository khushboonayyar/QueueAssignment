#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "user.h"

typedef struct Node {
    User data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);
int enqueue(Queue* q, User user);
int dequeue(Queue* q, User* removedUser);
int enqueueRandomUsers(Queue* q, int count);

#endif