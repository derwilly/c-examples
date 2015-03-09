/* a simple password generator */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFF 256

void generate_password(char* buf, int buflen, int length)
{
    srand(time(NULL));
    int r;
    char *cs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!$%&/()=?+#-.,*'_:;~'";
    int i;
    if(length < BUFF)
    {
        for(i = 0; i<=length-1; i++)
        {
            r = rand() % strlen(cs);
            buf[i] = cs[r];
        }
        buf[length] = '\0';
    }
    else
    {
        buf[0] = '\0';
    }
}

int main(int argc, char *argv[])
{
    char buf[BUFF];
    memset(buf, 0, sizeof(buf));

    int length = 0;
    int ret = 0;
    printf("password length: ");
    ret = scanf("%d", &length);

    generate_password(buf, BUFF, length);

    if(ret)
    {
        printf("generating a password with %d digits...\n", (unsigned)strlen(buf));
        printf("GENERATED PASSWORD: %s\n", buf);
    }
    else
    {
        printf("return of scanf was %d\n", ret);
    }

    return 0;
}
