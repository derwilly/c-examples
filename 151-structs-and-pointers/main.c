/* structs and pointers example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address
{
    char *fname;
    char *lname;
    char *email;
    int age;
};

struct Address *createAdress(char *fname, char *lname, char *email, int age)
{
    struct Address *adr = malloc(sizeof(struct Address));

    adr->fname = strdup(fname);
    adr->lname = strdup(lname);
    adr->email = strdup(email);
    adr->age = age;

    return adr;
}

void destroyAddress(struct Address *adr)
{
    free(adr->fname);
    free(adr->lname);
    free(adr->email);
    free(adr);
}

void printAddress(struct Address *adr)
{
    printf("First Name: %s\n", adr->fname);
    printf("Last Name: %s\n", adr->lname);
    printf("Email: %s\n", adr->email);
    printf("Age: %d\n", adr->age);
}

int main(int argc, char **argv)
{
    struct Address *Sam = createAdress("Sam", "Example", "sam@example.com", 40);
    struct Address *Mike = createAdress("Mike", "Example", "mike@example.com", 37);

    printAddress(Sam);
    printAddress(Mike);

    destroyAddress(Sam);
    destroyAddress(Mike);

    return 0;
}
