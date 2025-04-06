
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

bool Queue_Init(Queue *q);
bool EnQueue(Queue *q, int x);
bool DeQueue(Queue *q, int *x);
bool Queue_IsEmpty(Queue *q);
void Queue_Destroy(Queue *q);

#endif
