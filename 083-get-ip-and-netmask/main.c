/* Ferdinand Saufler <mail@saufler.de>
 * 22.03.2015
 *
 * get ip-address and netmask of an interface
 */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int sock;
    struct ifreq ifr;

    char *interface;
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    /* check the commandline argument */
    if(argc != 2)
    {
        fprintf(stderr,"usage: %s iface\n",argv[0]);
        return 1;
    }
    else if (strlen(argv[1]) < 2)
    {
        fputs("length of the interface must be at least 2 characters.\n",stderr);
        return 2;
    }

    interface = argv[1];

    /* retrieve an IPv4 address */
    ifr.ifr_addr.sa_family = AF_INET;

    /* copy the name of the interface in the ifreq structure */ 
    strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);

    /* get the ip-address */
    if(ioctl(sock, SIOCGIFADDR, &ifr) == -1)
    {
        printf("An Error occured: %s\n",strerror(errno));
        return(3);
    }

    /* print value of the ip-address */
    printf("IP address of %s: %s\n", interface, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

    /* get the netmask */
    if(ioctl(sock, SIOCGIFNETMASK, &ifr) == -1)
    {
        printf("An Error occured: %s\n",strerror(errno));
        return(3);
    }

    /* print the value of the netmask */
    printf("Netmask of %s: %s\n", interface, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
    
    /* close the socket descriptor */
    close(sock);

    return 0;
}
