
#include "Stack.h"

bool Stack_Init(Stack *s) {
    s->top = NULL;
    return true;
}

bool Stack_Push(Stack *s, int x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (!node) return false;
    node->data = x;
    node->next = s->top;
    s->top = node;
    return true;
}

bool Stack_Pop(Stack *s, int *x) {
    if (!s->top) return false;
    StackNode *tmp = s->top;
    if (x) *x = tmp->data;
    s->top = tmp->next;
    free(tmp);
    return true;
}

bool Stack_IsEmpty(Stack *s) {
    return s->top == NULL;
}

void Stack_Destroy(Stack *s) {
    StackNode *p = s->top;
    while (p) {
        StackNode *next = p->next;
        free(p);
        p = next;
    }
    s->top = NULL;
}
