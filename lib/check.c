/* check.c
 * Ferdinand Saufler
 * 06.02.2014
 */

int is_odd(int *val)
{
    if(*val % 2 == 0)
        return -1;
    else
        return 0;
}

int is_even(int *val)
{
    if(*val % 2 == 0)
        return 0;
    else
        return -1;
}

int is_vowel(char *c)
{
    if (*c == 'a' || *c == 'A' || *c == 'e' || *c == 'E' || *c == 'i'
    || *c == 'I' || *c =='o' || *c=='O' || *c == 'u' || *c == 'U')
        return 0;
    else
        return -1;
}

int is_leapyear(unsigned int *y)
{
    if(*y % 4 == 0)
        return 0;
    else
        return -1;
}

int is_palindrome(unsigned int *val)
{
    int tmp, r = 0;
    tmp = *val;

    while(tmp != 0)
    {
        r = r * 10;
        r = r + tmp % 10;
        tmp = tmp / 10;
    }

    /* check if r is the reverse of *val */
    if(*val == r)
        return 0;
    else
        return -1;
}
