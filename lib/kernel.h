/* kernel.h
 * Ferdinand Saufler <mail@saufler.de>
 * 15.07.2015
 */

#ifndef KERNEL_H
#define KERNEL_H

struct KernelVersionInfo {
    char *Sysname;
    char *VersionString;
    int MajorVersion;
    int MinorVersion;
    int PatchVersion;
};

int GetKernelVersion(struct KernelVersionInfo *kvi);

#endif
