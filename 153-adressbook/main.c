/* structs and pointers example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "address.h"

int main(int argc, char **argv)
{
    List *list = createList(destroyAddress);
    addNote(list, createAdress("Harry", "Potter", "harry@hogwarts.com", 20));
    addNote(list, createAdress("Hermine", "Granger", "Hermine@hogwarts.com", 19));
    addNote(list, createAdress("Ron", "Weasley", "ron@hogwarts.com", 19));
    Node *node = list->first;
    while(node != NULL)
    {
        printAddress(node->data);
        printf("\n");
        node = node->next;
    }

    node = list->first;
    while(node != NULL)
    {
        removeNode(list,node);
        node = node->next;
    }

    return 0;
}
