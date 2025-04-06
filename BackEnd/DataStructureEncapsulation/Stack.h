
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

bool Stack_Init(Stack *s);
bool Stack_Push(Stack *s, int x);
bool Stack_Pop(Stack *s, int *x);
bool Stack_IsEmpty(Stack *s);
void Stack_Destroy(Stack *s);

#endif
