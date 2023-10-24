#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct tnod  //linked list whose nodes have the TNOD type defined 
{
    char * word;
    int frequency;
    struct tnod *next;
}TNOD;
TNOD *first, *last;

char *citcuv(){  //reads one word and keeps it in the heap memory. The function returns the starting address of the
memory zone in which the word is maintained, or zero in the case of encountering any other
character.\\

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

int incnod(TNOD *p)  //loads the current data in a TNOD type node.
{
    if ((p->word = citcuv()) == 0) return -1;
    p -> frequency = 1;
    return 1;
}
void elibnod(TNOD *p)  //this function releases the zones from the heap memory allocated by the node that was defined in the previously
{
    free(p->word);
    free(p);
}

TNOD* add()  //This function allows the adding of a TNOD type node at the end of a simple linked list. This means that after the insertion of this node, it becomes the last node that has no successor.
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
TNOD* search(char *c) //This function searches, in the respective list, the node for which the word has as value the key (address) of a given string.
//The  pointer plays the key role and it is requested to be found the node that points to a given word.

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
