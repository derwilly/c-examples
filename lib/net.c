/* net.c
 * Ferdinand Saufler <mail@saufler.de>
 * 15.07.2015
 */

 #include <arpa/inet.h>
 #include <sys/socket.h>
 #include <ifaddrs.h>
 #include <netdb.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include "net.h"

/* returns a list of struct InterfaceInfo */
struct InterfaceInfo *GetInterfaceInfo()
{
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    struct sockaddr_in6 *sa6 __attribute__((unused));
    char *addr = NULL;
    char *netmask = NULL;
    struct InterfaceInfo *node = NULL;
    struct InterfaceInfo *first = NULL;
    struct InterfaceInfo *ptr;

    getifaddrs (&ifap);

    for (ifa = ifap; ifa; ifa = ifa->ifa_next)
    {
        node = (struct InterfaceInfo *)malloc(sizeof(struct InterfaceInfo));
        node->Next = NULL;
        node->Ipv4Address = NULL;
        node->Ipv4Netmask = NULL;
        node->Ipv6Address = NULL;
        node->Ipv6Netmask = NULL;
        node->Name = strdup(ifa->ifa_name);
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            node->Ipv4Address = strdup(addr);
            sa = (struct sockaddr_in *) ifa->ifa_netmask;
            netmask = inet_ntoa(sa->sin_addr);
            node->Ipv4Netmask = strdup(netmask);
        }
        else if (ifa->ifa_addr->sa_family == AF_INET6)
        {
            sa6 = (struct sockaddr_in6 *) ifa->ifa_addr;
            getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), addr, sizeof(addr), NULL, 0, NI_NUMERICHOST);
            node->Ipv6Address = strdup(addr);
            getnameinfo(ifa->ifa_netmask, sizeof(struct sockaddr_in6), netmask, sizeof(netmask), NULL, 0, NI_NUMERICHOST);
            node->Ipv6Netmask = strdup(netmask);
        }
        else
        {
            node = NULL;
        }

        if(first == NULL)
        {
            first = node;
        }
        else
        {
            ptr = first;
            while(ptr->Next != NULL)
                ptr = ptr->Next;

            ptr->Next = node;
            ptr = ptr->Next;
            ptr->Next = NULL;
        }
    }

    freeifaddrs(ifap);

    return first;
}

void FreeInterfaceInfo(struct InterfaceInfo *ifi)
{
    while(ifi != NULL)
    {
        free(ifi->Name);
        free(ifi->Ipv4Address);
        free(ifi->Ipv6Address);
        free(ifi->Ipv4Netmask);
        free(ifi->Ipv6Netmask);
        struct InterfaceInfo *tmp = ifi;
        ifi = ifi->Next;
        free(tmp);
    }
}
