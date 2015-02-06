/* a simple addressbook with linked lists */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include "address.h"

int main(int argc, char **argv)
{
    /* create a list */
    List *list = createList(destroyAddress);

    /* add a bunch of nodes to the list */
    pushNode(list, createAddress("Harry", "Potter", "harry@hogwarts.com", 20));
    pushNode(list, createAddress("Bart", "Simpson", "bart@homersworld.com", 20));
    pushNode(list, createAddress("Hermine", "Granger", "Hermine@hogwarts.com", 19));
    pushNode(list, createAddress("Ron", "Weasley", "ron@hogwarts.com", 19));
    pushNode(list, createAddress("Micky", "Mouse", "Micky@mouse.com", 19));

    /* remove the second node */
    removeNode(list,list->ptr->next);

    /* remove the last node */
    popNode(list);

    /* count the elements */
    printf("the list has now %d entries.\n\n", countNodes(list));

    /* set the list-pointer to the begin of the list */
    list->ptr = list->first;

    /* print all elements of the list */
    while(list->ptr != NULL)
    {
        printAddress(list->ptr->data);
        list->ptr = list->ptr->next;
    }

    /* remove all elements from the list */
    clearList(list);

    return 0;
}
