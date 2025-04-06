
#include "queue.h"

bool Queue_Init(Queue *q) {
    QueueNode *dummy = (QueueNode *)malloc(sizeof(QueueNode));
    if (!dummy) return false;
    dummy->next = NULL;
    q->front = q->rear = dummy;
    return true;
}

bool EnQueue(Queue *q, int x) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!node) return false;
    node->data = x;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
    return true;
}

bool DeQueue(Queue *q, int *x) {
    if (q->front == q->rear) return false;
    QueueNode *tmp = q->front->next;
    if (x) *x = tmp->data;
    q->front->next = tmp->next;
    if (q->rear == tmp) q->rear = q->front;
    free(tmp);
    return true;
}

bool Queue_IsEmpty(Queue *q) {
    return q->front == q->rear;
}

void Queue_Destroy(Queue *q) {
    while (q->front) {
        QueueNode *next = q->front->next;
        free(q->front);
        q->front = next;
    }
    q->rear = NULL;
}
