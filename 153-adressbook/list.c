#include <stdlib.h>
#include "list.h"

List *createList(freeFunction fnPtr)
{
    List *lptr = (List*)malloc(sizeof(List));
    lptr->first = NULL;
    lptr->last = NULL;
    lptr->elements = 0;
    lptr->fnPtr = fnPtr;
    return lptr;
}

void addNote(List *list, void *data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list->elements == 0)
    {
        list->first = newNode;
        list->last = newNode;
        list->elements++;
    }
    else
    {
        Node *lastNode = list->last;
        lastNode->next = newNode;
        list->last = newNode;
        list->elements++;
    }
}

void removeNode(List *list, Node *node)
{
    list->fnPtr(node->data);
    list->elements--;
    free(node);
}
