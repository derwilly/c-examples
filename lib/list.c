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

void appendNode(List *list, void *data)
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
    // if there is no node in the list, break up
    if(list->first == NULL)
    {
        return;
    }

    // if the node is the first element, just delete it
    if(node == list->first)
    {
        list->first = node->next;
        list->fnPtr(node->data);
        list->elements--;
        free(node);
    }
    else
    {
        Node *ptr = list->first;
        Node *prevNode;
        while(node != NULL)
        {
            prevNode = ptr;
            ptr = ptr->next;
            if(ptr == node)
            {
                prevNode->next = ptr->next;
                if(prevNode->next == NULL)
                {
                    list->last = prevNode;
                }
                list->fnPtr(node->data);
                list->elements--;
                free(node);
                break;
            }
        }
    }
}
