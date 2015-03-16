/* Ferdinand Saufler <mail@saufler.de>
 * 14.03.2015
 * vars */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int legs = 4;
    static float pi = 3.1416f;
    double moondis = 384400123.459;
    char a_starts = 'A';
    char fname[] = "Flash";
    char lname[] = "Gordon";
    char *p = fname;

    printf("My cat has %d legs.\n", legs);
    printf("Pi equals ~%f.\n", pi);
    printf("The distance to the moon is %f meters.\n", moondis);
    printf("The alphabet starts with an %c.\n", a_starts);
    printf("My first name is %s.\n", fname);
    printf("My last name is %s.\n", lname);
    printf("My full name is %s %s.\n",fname,lname);
    printf("The secound character of my first name is \"%c\".\n",*++p);

    return 0;
}
