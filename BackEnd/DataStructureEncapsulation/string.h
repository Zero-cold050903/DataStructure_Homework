#ifndef STRING_H
#define STRING_H

#define MAXSIZE 100

typedef struct 
{
    char data[MAXSIZE];
    int len;
} SString;

int StrInsert(SString *S, int pos, SString T);
int StrDelete(SString *S, int pos, int len);
int StrCompare(SString s, SString t);
void Next(SString *p, int next[]);
int KMP(SString *s, SString *p, int next[]);

#endif // STRING_H
