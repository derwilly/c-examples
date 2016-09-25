#include <stdio.h>
#include <stdlib.h>
#include <net.h>

void test_net()
{
    struct InterfaceInfo *ifi, *save_ptr;

    ifi = GetInterfaceInfo();
    save_ptr = ifi;

    while(ifi != NULL)
    {
        printf("InterfaceName: %s\n",ifi->Name);
        printf("Ipv4Address: %s\n",ifi->Ipv4Address);
        printf("Ipv4Netmask: %s\n",ifi->Ipv4Netmask);
        printf("Ipv6Address: %s\n",ifi->Ipv6Address);
        printf("Ipv6Netmask: %s\n\n",ifi->Ipv6Netmask);
        ifi = ifi->Next;
    }

    FreeInterfaceInfo(save_ptr);
}
