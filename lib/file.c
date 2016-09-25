/* file.c
 * Ferdinand Saufler
 * 06.11.2014
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "file.h"

/*
 * int file_exists()
 * checks if a given file exists
 * return 0 if the file exists
 * if the file does not exist it returns -1
 */
int file_exists(const char *fpath)
{
    if(access(fpath, F_OK) != -1)
    {
        /* file exists */
        return 0;
    }
    else
    {
        /* file does not exist */
        return -1;
    }
}

/* directory_exists()
 * returns 0 if the directory exists
 * -1 if not */
int directory_exists(const char* path)
{
    if (path == NULL)
    {
        return -1;
    }

    DIR *path_dir;
    int d_exists = -1;

    path_dir = opendir(path);

    if (path_dir != NULL)
    {
        d_exists = 0;
        (void) closedir (path_dir);
    }
    return d_exists;
}

/* returns the file size in bytes */
unsigned long get_filesize(const char *path)
{
    FILE *fp;
    fp = fopen(path,"r");
    fseek(fp, 0L, SEEK_END);
    unsigned long sz = ftell(fp);
    return sz;
}

/*
 * returnes a formatted string of the filesize
 * for example 1024B => 1KB
 */
void get_format_size(unsigned long size, char* buf)
{
    double size_d = size;

    if(size_d <= 0)
    {
        buf = (char*)"0B";
    }
    else
    {
        if(size <= 1024)
        {
            sprintf(buf,"%.0lf",size_d);
            strcat(buf, "B");
        }
        else
        {
            size_d /= 1024;
            if(size_d <= 1024)
            {
                sprintf(buf,"%.0lf",size_d);
                strcat(buf, "KB");
            }
            else
            {
                size_d /= 1024;
                if(size_d <= 1024)
                {
                    sprintf(buf,"%.2lf",size_d);
                    strcat(buf, "MB");
                }
                else
                {
                    size_d /= 1024;
                    if(size_d <= 1024)
                    {
                        sprintf(buf,"%.2lf",size_d);
                        strcat(buf, "GB");
                    }
                    else
                    {
                        size_d /= 1024;
                        if(size_d <= 1024)
                        {
                            sprintf(buf,"%.2lf",size_d);
                            strcat(buf, "TB");
                        }
                        else
                        {
                            sprintf(buf,"%.0lf",size_d);
                            strcat(buf, ">TB");
                        }
                    }
                }
            }
        }
    }
}
