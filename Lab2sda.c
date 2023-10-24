#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct tnod
{
    char * word;
    int frequency;
    struct tnod *next;
}TNOD;
TNOD *first, *last;

char *citcuv(){
    char t[250],c;
    char *p;
    int i=0;
    while((c=getchar()) >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
    { t[i]=c;
        i++;}
    t[i] = '\0';
    if (t[0] == '\0')
        return 0;

    if ((p = (char *) malloc(i)) == 0) {
        printf("Insufficient memory \n");
        exit(1);
    }

    strcpy(p,t);
    return 0;
}

int incnod(TNOD *p)
{
    if ((p->word = citcuv()) == 0) return -1;
    p -> frequency = 1;
    return 1;
}
void elibnod(TNOD *p)
{
    free(p->word);
    free(p);
}

TNOD* add()
{
    TNOD *p;
    int n;

    n = sizeof(TNOD);
    if (((p = (TNOD *)malloc (n)) != 0) &&
        (incnod(p) == 1))
    {
        if (first == 0)
            first = last = p;
        else
        {
            last->next = p;
*/
            last = p;
        }
        p->next = 0;
        return p;
    }
    if (p == 0)
    {
        printf ("Insufficient memory \n");
        exit(1);
    }
    elibnod(p);
    return 0;
}
TNOD* search(char *c)
{
    extern TNOD *first;
    TNOD *p;
    for (p = first; p; p = p->next)
        if (strcmp (p-> word, c) == 0)
            return p;
    return 0;
}
void erase()
{
    extern TNOD *first, *last;
    TNOD *q, *q1;
    q1 = 0;
    q = first;
    if (q == 0)
        return;
    while (q != last)
    {
        q1 = q;
        q = q-> next;
    }
    if (q == first)
        first = last = 0;
    else
    {
        q1->next = 0;
        last = q1;
    }
    elibnod (q);
}


int main(){
    TNOD *p, *q;
    first = last = 0;
    while((p = add())!= 0)
        if ((q = search(p-> word))!= last)
        {
            q->frequency ++;
            erase();
        }

    for (p = first; p; p = p->next)
        printf ("\n The word %s has frequency =%d \n", p->word, p->frequency);
}