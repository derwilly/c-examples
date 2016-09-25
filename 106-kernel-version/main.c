/* Ferdinand Saufler <mail@saufler.de>
 * 25.09.2016
 * this program prints information about the current used kernel. */

#include <stdio.h>
#include <stdlib.h>
#include <file.h>
#include <kernel.h>

int main()
{
    struct KernelVersionInfo kvi;
    GetKernelVersion(&kvi);

    printf("Sysname: %s\n", kvi.Sysname);
    printf("VersionString: %s\n", kvi.VersionString);
    printf("MajorVersion: %d\n", kvi.MajorVersion);
    printf("MinorVersion: %d\n", kvi.MinorVersion);
    printf("PatchVersion: %d\n", kvi.PatchVersion);

    return 0;
}
