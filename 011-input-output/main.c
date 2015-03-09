/* Simple input output */

#include <stdio.h>
#include <string.h>

#define BUF_LEN 64

typedef struct Human
{
    int age;
    char fname[BUF_LEN];
} Human;

int clear_stdin()
{
    while (getchar()!='\n');
    return 0;
}

int main(int argc, char *argv[])
{
    Human you = {.age = 0};
    char *input = NULL;
    int ret = 0;

    while(input == NULL)
    {
        printf("whats your first name? ");
        input = fgets(you.fname, BUF_LEN-1, stdin);
        if(*input == '\n')
        {
            input = NULL;
        }
    }

    while(ret < 1)
    {
        printf("How old are you? ");
        ret = fscanf(stdin, "%d", &you.age);
        clear_stdin();
    }

    printf("%s",you.fname);
    printf("%d\n",you.age);

    return 0;
}
