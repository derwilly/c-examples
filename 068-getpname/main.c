/* Ferdinand Saufler <mail@saufler.de>
 * 29.04.2015
 *
 * get process name
 */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

pid_t find_pname(const char* name)
{
    DIR* dir;
    struct dirent* ent;
    char* endptr;
    char buf[1024];

    if ((dir = opendir("/proc")) == NULL)
    {
        perror("cant open /proc folder");
        return -1;
    }

    while((ent = readdir(dir)) != NULL)
    {
        /* if the folder is not entirly numeric, ignore it */
        long lpid = strtol(ent->d_name, &endptr, 10);
        if (*endptr != '\0')
        {
            continue;
        }

        /* try to open /proc/%ld/cmdline */
        snprintf(buf, sizeof(buf), "/proc/%ld/cmdline", lpid);
        FILE* fp = fopen(buf, "r");

        if (fp)
        {
            if (fgets(buf, sizeof(buf), fp) != NULL)
            {
                /* the process name is the first item in the file */
                char* first = strtok(buf, " ");
                if (!strcmp(first, name))
                {
                    fclose(fp);
                    closedir(dir);
                    return (pid_t)lpid;
                }
            }
            fclose(fp);
        }

    }

    closedir(dir);
    return -1;
}


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("usage: %s pname1 pname2 ...\n", argv[0]);
        return 1;
    }

    int i;
    for(i = 1; i < argc; ++i)
    {
        pid_t pid = find_pname(argv[i]);
        if (pid == -1)
        {
            printf("%s: not found\n", argv[i]);
        }
        else
        {
            printf("%s: %d\n", argv[i], pid);
        }
    }

    return 0;
}
