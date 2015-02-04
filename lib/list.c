#include <stdlib.h>
#include "list.h"

List *createList(freeFunction fnPtr)
{
    List *lptr = (List*)malloc(sizeof(List));
    lptr->first = NULL;
    lptr->last = NULL;
    lptr->ptr = NULL;
    lptr->elements = 0;
    lptr->fnPtr = fnPtr;
    return lptr;
}

void clearList(List *list)
{
    Node *node;

    // if there is no node in the list, break up
    if(list->elements < 1)
    {
        return;
    }
    else
    {
        list->ptr = list->first;
        while(list->ptr != NULL)
        {
            node = list->ptr;
            list->fnPtr(node->data);
            list->elements--;
            free(node);
            list->ptr = list->ptr->next;
        }

        // reset all list properties
        list->first = NULL;
        list->last = NULL;
        list->ptr = NULL;
    }
}

void removeNode(List *list, Node *node)
{
    // if there is no node in the list, break up
    if(list->elements < 1)
    {
        return;
    }
    else if(list->elements == 1)
    {
        // free and detroy the first element
        list->fnPtr(list->first->data);

        // update list values
        list->first = NULL;
        list->last = NULL;
        list->ptr = NULL;
        list->elements--;

        // free the node
        free(list->first);
    }
    else
    {
        Node *ptr = list->first;
        Node *prevNode = NULL;
        while(ptr != NULL)
        {
            /* ptr is the actual node in the while loop,
               prevNode is the node before ptr */
            prevNode = ptr;
            ptr = ptr->next;
            if(ptr == node)
            {

                // now set the next property of the node before the deletion-node
                // to the node after the deletion node
                prevNode->next = ptr->next;

                // if the node before the deletion-node is the last-node in the
                // list, update the list->last proberty
                if(prevNode->next == NULL)
                {
                    list->last = prevNode;
                }

                // release the data and clean up the memory
                list->fnPtr(node->data);
                list->elements--;
                free(node);
                break;
            }
        }
    }
}

void pushNode(List *list, void *data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list->elements == 0)
    {
        list->first = newNode;
        list->last = newNode;
        list->ptr = list->first;
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

void popNode(List *list)
{
    // if there is no node in the list, break up
    if(list->elements < 1)
    {
        return;
    }
    else if(list->elements == 1)
    {
        // free and detroy the first element
        list->fnPtr(list->first->data);

        // update list values
        list->first = NULL;
        list->last = NULL;
        list->ptr = NULL;
        list->elements--;

        // free the node
        free(list->first);
    }
    else
    {
        /* we have to update the property "next" of the secound last node in
         * the list. then we can delete the last element in the list. */
        Node *ptr = list->first;
        Node *prevNode = NULL;

        // find the secound-last node (prevNode)
        while(ptr != list->last)
        {
            prevNode = ptr;
            ptr = ptr->next;
        }

        // check and update the list-node pointer, if the list-pointer points
        // to the last element in the list, set it to the first element in the list
        if(list->ptr == list->last)
        {
            list->ptr = prevNode;
        }

        // free and detroy the last element
        list->fnPtr(list->last->data);
        list->elements--;
        free(list->last);

        // set the next property of prevNode to NULL
        prevNode->next = NULL;

        // set the secound last node the last node in the list
        list->last = prevNode;
    }
}

int countNodes(List *list)
{
    return list->elements;
}
