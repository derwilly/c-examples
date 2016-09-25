/* net.h
 * Ferdinand Saufler <mail@saufler.de>
 * 15.07.2015
 */

#ifndef NET_H
#define NET_H

struct InterfaceInfo {
    struct InterfaceInfo *Next;      /* pointer to the next element */
    char *Name;
    char *Ipv4Address;
    char *Ipv6Address;
    char *Ipv4Netmask;
    char *Ipv6Netmask;
};

struct InterfaceInfo *GetInterfaceInfo();
void FreeInterfaceInfo(struct InterfaceInfo *ifi);

#endif
