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
