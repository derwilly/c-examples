/* Ferdinand Saufler <mail@saufler.de>
 * 22.03.2015
 *
 * this example prints the ip-adresses of a given host
 */

#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    /* "status", stores the return value of getaddrinfo() */
    int status;

    /* store the ip-addresses in a char array, the lenth of an
     * IPv6 address on my machine is defined in
     * in.h (/usr/include/netinet/in.h) on line 233 - its 46
     * characters long */
    char ip[INET6_ADDRSTRLEN];

    /* man 3 getaddrinfo
     * struct addrinfo {
     *     int              ai_flags;
     *     int              ai_family;
     *     int              ai_socktype;
     *     int              ai_protocol;
     *     socklen_t        ai_addrlen;
     *     struct sockaddr *ai_addr;
     *     char            *ai_canonname;
     *     struct addrinfo *ai_next;
     * };
     */
    struct addrinfo hints, *result, *ptr;

    /* check the commandline argument */
    if(argc != 2 || strlen(argv[1]) < 3)
    {
        fprintf(stderr,"usage: %s host\n",argv[0]);
        return 1;
    }

    /* make sure hints is empty */
    memset(&hints, 0, sizeof(hints));

    /* we dont care about IP4 or IP6, use AF_INET or
     * AF_INET6 to force the ip-version */
    hints.ai_family = AF_UNSPEC;

    /* use a TCP Stream Socket */
    hints.ai_socktype = SOCK_STREAM;

    /* man 3 getaddrinfo
     * the secound argument of getaddrinfo() is "0", because
     * we dont search for a specific service, we just want
     * the ip-address. getaddrinfo() creates a linked list of,
     * results, in that case "result" points to the first entry
     * in the list. */
    if((status = getaddrinfo(argv[1], 0, &hints, &result)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("ip-adresses for host %s:\n", argv[1]);

    /* getaddrinfo() writes a linked list to result (**res), now
     * iterate over that linked list while ptr != NULL and
     * print out the ip-address */
    for(ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        void *address;
        char *version;

        /* if its a IPv4 address */
        if (ptr->ai_family == AF_INET)
        { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)ptr->ai_addr;
            address = &(ipv4->sin_addr);
            version = "IPv4";
        }
        /* if its a IPv6 address */
        else if(ptr->ai_family == AF_INET6)
        {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)ptr->ai_addr;
            address = &(ipv6->sin6_addr);
            version = "IPv6";
        }
        else
        {
            continue;
        }

        /* convert the ip-address to a string.
         * man 3 inet_ntop:
         * "inet_ntop - convert IPv4 and IPv6 addresses from
         * binary to text form" */
        inet_ntop(ptr->ai_family, address, ip, sizeof(ip));

        /* print the string */
        printf("  %s: %s\n", version, ip);
    }

    /* cleanup memory, free the linked list */
    freeaddrinfo(result);

    return 0;
}
