/* kernel.c
 * Ferdinand Saufler <mail@saufler.de>
 * 15.07.2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include "kernel.h"

int GetKernelVersion(struct KernelVersionInfo *kvi)
{
    struct utsname buffer;

    if (uname(&buffer) != 0)
    {
        return -1;
    }
    kvi->Sysname = strdup(buffer.sysname);
    kvi->VersionString = strdup(buffer.release);
    sscanf(buffer.release,"%d.%d.%d",&kvi->MajorVersion,&kvi->MinorVersion,&kvi->PatchVersion);

    return 0;
}
