/* a simple linked list */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int ivalue;
    struct Node *next;
} Node;

Node *createNode(int ivalue, Node* next)
{
    Node *nptr = (Node*)malloc(sizeof(Node));

    nptr->ivalue = ivalue;
    nptr->next = next;

    return nptr;
}

void destroyList(Node *list)
{
    Node *node;
    while(list!=NULL)
    {
        node = list;
        list = list->next;
        free(node);
    }
}

void printList(Node *list)
{
    int index = 0;
    Node *node = list;
    while(node!=NULL)
    {
        printf("\nnode %d:\n\tvalue: %d\n\tnext: %p",index,node->ivalue,node->next);
        node = node->next;
        index++;
    }
}

int main(int argc, char **argv)
{
    Node *list;
    Node *first = createNode(10,NULL);
    Node *secound = createNode(20,NULL);
    Node *third = createNode(30,NULL);
    first->next = secound;
    secound->next = third;

    list = first;

    printList(list);
    printf("\n");
    destroyList(list);

    return 0;
}
