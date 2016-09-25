/* a simple addressbook with linked lists */

#include <stdio.h>
#include <string.h>
#include "test_list.h"
#include "test_file.h"
#include "test_str.h"
#include "test_kernel.h"
#include "test_net.h"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        if(strcmp("list",argv[1])==0)
        {
            test_list();
        }
        else if(strcmp("file",argv[1])==0)
        {
            test_file();
        }
        else if(strcmp("str",argv[1])==0)
        {
            test_str();
        }
        else if(strcmp("kernel",argv[1])==0)
        {
            test_kernel();
        }
        else if(strcmp("net",argv[1])==0)
        {
            test_net();
        }
        else if(strcmp("all",argv[1])==0)
        {
            test_list();
            test_file();
            test_str();
            test_kernel();
            test_net();
        }
    }
    else
    {
        printf("usage: %s [test]\n",argv[0]);
    }
    return 0;
}
