
#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList *L);
bool InsertList(LinkList L, int i, int x);
bool DeleteList(LinkList L, int i, int *x);
void PrintList(LinkList L);
void DestroyList(LinkList L);

#endif
