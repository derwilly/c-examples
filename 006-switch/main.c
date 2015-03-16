/* Ferdinand Saufler <mail@saufler.de>
 * 14.03.2015
 * switch */

#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("usage %s [string]\n",argv[0]);
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char c = argv[1][i];

        switch(c) {
            case 'a':
            case 'A':
                printf("%d: a like apple.\n", i);
                break;

            case 'c':
            case 'C':
                printf("%d: c like charly.\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: e like echo.\n", i);
                break;

            case 'f':
            case 'F':
                printf("%d: f like a fox.\n", i);
                break;

            case 'm':
            case 'M':
                printf("%d: m like mother.\n", i);
                break;

            case 'l':
            case 'L':
                printf("%d: l like lollipop.\n", i);
                break;

            default:
                printf("%d: %c i dont know this character\n", i, c);
        }
    }

    return 0;
}
