/* structs and pointers example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include "address.h"

int main(int argc, char **argv)
{
    /* create a list */
    List *list = createList(destroyAddress);

    /* add three nodes to the list */
    appendNode(list, createAddress("Harry", "Potter", "harry@hogwarts.com", 20));
    appendNode(list, createAddress("Bart", "Simpson", "bart@homersworld.com", 20));
    appendNode(list, createAddress("Hermine", "Granger", "Hermine@hogwarts.com", 19));
    appendNode(list, createAddress("Ron", "Weasley", "ron@hogwarts.com", 19));

    /* create a note pointer, and let i point on the first element of the list */
    Node *node = list->first;

    /* remove the second node */
    removeNode(list,node->next);

    /* reset the node-pointer to the begin of the list */
    node=list->first;

    /* print all elements of the list */
    while(node != NULL)
    {
        printAddress(node->data);
        printf("\n");
        node = node->next;
    }

    /* reset the node-pointer to the begin of the list */
    node = list->first;

    /* destroy all list elements */
    while(node != NULL)
    {
        removeNode(list,node);
        node = node->next;
    }

    return 0;
}
