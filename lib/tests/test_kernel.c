#include <stdio.h>
#include <stdlib.h>
#include <kernel.h>

void test_kernel()
{
    struct KernelVersionInfo kvi;

    GetKernelVersion(&kvi);

    printf("Kernel Version: %s\n", kvi.VersionString);
    printf("Major Version: %d\n", kvi.MajorVersion);
    printf("Minor Version: %d\n", kvi.MinorVersion);
    printf("Patch Version: %d\n", kvi.PatchVersion);
}
