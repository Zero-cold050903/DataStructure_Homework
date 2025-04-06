
#include "String.h"
#include <stdbool.h>

int StrInsert(SString *S, int pos, SString T)
{
    int i;
    if (pos < 0 || pos > S->len) return 0;
    if (S->len + T.len <= MAXSIZE)
    {
        for (i = S->len + T.len - 1; i >= T.len + pos; i--)
            S->data[i] = S->data[i - T.len];
        for (i = 0; i < T.len; i++)
            S->data[i + pos] = T.data[i];
        S->len += T.len;
    }
    else if (pos + T.len <= MAXSIZE)
    {
        for (i = MAXSIZE - 1; i > T.len + pos - 1; i--)
            S->data[i] = S->data[i - T.len];
        for (i = 0; i < T.len; i++)
            S->data[i + pos] = T.data[i];
        S->len = MAXSIZE;
    }
    else
    {
        for (i = 0; i < MAXSIZE - pos; i++)
            S->data[i + pos] = T.data[i];
        S->len = MAXSIZE;
    }
    return 1;
}

int StrDelete(SString *S, int pos, int len)
{
    int i;
    if (pos < 0 || pos > (S->len - len)) return 0;
    for (i = pos + len; i < S->len; i++)
        S->data[i - len] = S->data[i];
    S->len -= len;
    return 1;
}

int StrCompare(SString s, SString t)
{
    int i;
    for (i = 0; i < s.len && i < t.len; i++)
    {
        if (s.data[i] != t.data[i])
            return (s.data[i] - t.data[i]);
    }
    return (s.len - t.len);
}

void Next(SString *p, int next[]) 
{
    int k = -1;
    int j = 0; 
    next[0] = -1;

    while (j < p->len - 1) 
    {
        if (k == -1 || p->data[j] == p->data[k]) 
OBOBOB        {
            ++k;
            ++j;
            next[j] = k;
OBOBOB        } 
        else 
        {
            k = next[k];
        }
    }
}
OBOBOB
OBOBOBint KMP(SString *s, SString *p, int next[]) 
{
    int t1 = 0;
    int t2 = 0;

    while (t1 < s->len && t2 < p->len) 
    {
        if (t2 == -1 || s->data[t1] == p->data[t2]) 
        {
            t1++;
            t2++;
        } 
        else 
        {
            t2 = next[t2];
        }
    }

    if (t2 == p->len)
    {
        return t1 - t2 + 1;  
    } 
    else 
    {
        return 0; 
    }
}
