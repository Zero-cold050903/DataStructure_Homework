
#include "LinkList.h"

bool InitList(LinkList *L) {
    *L = (LNode *)malloc(sizeof(LNode));
    if (!*L) return false;
    (*L)->next = NULL;
    return true;
}

bool InsertList(LinkList L, int i, int x) {
    if (i < 1) return false;
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p) return false;
    LNode *node = (LNode *)malloc(sizeof(LNode));
    if (!node) return false;
    node->data = x;
    node->next = p->next;
    p->next = node;
    return true;
}

bool DeleteList(LinkList L, int i, int *x) {
    if (i < 1) return false;
    LNode *p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p->next) return false;
    LNode *q = p->next;
    if (x) *x = q->data;
    p->next = q->next;
    free(q);
    return true;
}

void PrintList(LinkList L) {
    LNode *p = L->next;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void DestroyList(LinkList L) {
    LNode *p = L;
    while (p) {
        LNode *next = p->next;
        free(p);
        p = next;
    }
}
