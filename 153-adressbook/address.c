#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"

Address *createAdress(char *fname, char *lname, char *email, int age)
{
    Address *adr = malloc(sizeof(Address));

    adr->fname = strdup(fname);
    adr->lname = strdup(lname);
    adr->email = strdup(email);
    adr->age = age;

    return adr;
}

void destroyAddress(Address *adr)
{
    free(adr->fname);
    free(adr->lname);
    free(adr->email);
    free(adr);
}

void printAddress(Address *adr)
{
    printf("First Name: %s\n", adr->fname);
    printf("Last Name: %s\n", adr->lname);
    printf("Email: %s\n", adr->email);
    printf("Age: %d\n", adr->age);
}
