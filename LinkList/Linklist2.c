#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node * next;
} SLink;

void InitList (SLink * * sq)
{
    * sq = (SLink *) malloc (sizeof (SLink));

    for (int i = 1; i <= 10; i ++)
    {
        (* sq) -> next = (SLink *) malloc (sizeof (SLink));
        (* sq) -> data = i*100;
        sq = & ((* sq) -> next);
    }
    (* sq) -> next = 0;
}

int main (void)
{
    SLink * sl;
    InitList (& sl);
    while (sl->next) printf ("%d\n", sl -> data), sl = sl -> next;

    return 0;
}