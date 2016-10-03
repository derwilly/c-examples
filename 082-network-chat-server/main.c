/* Ferdinand Saufler <mail@saufler.de>
 * 22.03.2015
 * last updated on 03.10.2016
 * a simple chatserver
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define VERSION "0.0.2"

void *get_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char** argv)
{
    char port[5] = {};                  // port
    fd_set fd_master;                   // master file descriptor list
    fd_set fd_read;                     // temporary file descriptor list for select()
    int max_fd;                         // number of maximum file descriptors
    int listener;                       // listening socket descriptor
    int new_fd;                         // connected last, socket descriptor
    struct sockaddr_storage remoteaddr; // client remoteaddr
    char remote_ip[INET6_ADDRSTRLEN];   // remote addr as string
    char local_ip[INET6_ADDRSTRLEN];    // server addr as string
    socklen_t addrlen;                  // length of remoteaddr
    char buf[1024];                     // buffer for client data
    int bytes_recved;                   // number of bytes received by recv()
    int optval = 1;                     // 4th argument of setsockopt, reuse address
    int i, j, status;
    struct addrinfo hints, *result, *ptr;


    /* check the commandline argument for the port */
    if(argc != 2)
    {
        fprintf(stderr,"usage: %s port\n",argv[0]);
        exit(1);
    }
    else if ((strtol(argv[1], NULL, 10) < 1024) || (strtol(argv[1], NULL, 10) > 65535))
    {
        strcpy(port,"7177");
        fputs("port is out of range. set port to 7117\n",stderr);
    }
    else
    {
        printf("setting port to %s\n",argv[1]);
        strcpy(port,argv[1]);
    }
    printf("simple chat version %s\n", VERSION);

    /* make sure hints is empty */
    memset(&hints, 0, sizeof(hints));

    /* reset the fd-sets */
    FD_ZERO(&fd_master);
    FD_ZERO(&fd_read);

    /* we dont care about IP4 or IP6, use AF_INET or
     * AF_INET6 to force the ip-version */
    hints.ai_family = AF_UNSPEC;

    /* use a TCP Stream Socket */
    hints.ai_socktype = SOCK_STREAM;

    /* choose my local ip */
    hints.ai_flags = AI_PASSIVE;

    /* man 3 getaddrinfo
     * "If the AI_PASSIVE flag is specified in hints.ai_flags, and node is NULL,
     * then  the  returned socket  addresses  will be suitable for bind(2)ing
     * a socket that will accept(2) connections..." */
    if ((status = getaddrinfo(NULL, port, &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(2);
    }

    /* iterate over the linked list "result", which was created by getaddrinfo()
     * to find a suitable bind address */
    for(ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        /* try to create a new socket */
        listener = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (listener < 0)
            continue;

        /* we want to reuse the address if we want */
        setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int));

        if (bind(listener, ptr->ai_addr, ptr->ai_addrlen) < 0)
        {
            close(listener);
            continue;
        }
        break;
    }

    /* if ptr == NULL => bind() failed. */
    if (ptr == NULL)
    {
        fprintf(stderr, "bind(): failed to bind.\n");
        exit(2);
    }

    /* get local ip */
    void *address = get_addr(ptr->ai_addr);

    /* convert the ip-address to a string.
     * man 3 inet_ntop:
     * "inet_ntop - convert IPv4 and IPv6 addresses from
     * binary to text form" */
    inet_ntop(ptr->ai_family, address, local_ip, sizeof(local_ip));

    /* free the linked list result, we dont need it anymore */
    freeaddrinfo(result);

    /* listen */
    if(listen(listener, 5) == 0)
    {
        printf("listening to %s:%s\n",local_ip,port);
    }
    else
    {
        fprintf(stderr,"cant listen to socket.");
        exit(4);
    }

    /* add the listener to the master set */
    FD_SET(listener, &fd_master);

    /* monitor the max file descriptor */
    max_fd = listener;

    /* main loop */
    while(1)
    {
        /* copy the master set to the read set */
        fd_read = fd_master;
        if (select(max_fd+1, &fd_read, NULL, NULL, NULL) == -1)
        {
            printf("select error: %s\n", strerror(errno));
            exit(5);
        }

        /* iterate through the descriptors, looking for data to read */
        for(i = 0; i <= max_fd; i++)
        {
            /* found a descriptor */
            if (FD_ISSET(i, &fd_read))
            {
                if (i == listener)
                {
                    /* handle a new connection */
                    addrlen = sizeof remoteaddr;
                    new_fd = accept(listener,(struct sockaddr *)&remoteaddr,&addrlen);
                    if (new_fd == -1)
                        printf("accept error: %s\n", strerror(errno));
                    else
                    {
                        /* add the new descriptor to the master set */
                        FD_SET(new_fd, &fd_master);
                        /* if the new descriptor is greater than max_fd,
                         * update max_fd */
                        if (new_fd > max_fd) {
                            max_fd = new_fd;
                        }
                        printf("server: new connection from %s on "
                            "socket %d\n",
                            inet_ntop(remoteaddr.ss_family,
                            get_addr((struct sockaddr*)&remoteaddr),
                            remote_ip, INET6_ADDRSTRLEN),
                            new_fd);
                    }
                } else {
                    /* handle data from the client */
                    if ((bytes_recved = recv(i, buf, sizeof buf, 0)) <= 0) {
                        /* an error occured, or client closed connection */
                        if (bytes_recved == 0)
                        {
                            /* connection closed */
                            printf("server: socket %d hung up\n", i);
                        }
                        else
                        {
                            printf("accept recv: %s\n", strerror(errno));
                        }
                        /* close the connection */
                        close(i);

                        /* update the master set, remove descriptor from the master set */
                        FD_CLR(i, &fd_master);
                    }
                    else
                    {
                        /* we got some data */
                        /* print the data to the server console */
                        printf("[client::%d] %s", i, buf);

                        for(j = 0; j <= max_fd; j++)
                        {
                            /* send the data to every connected client */
                            if (FD_ISSET(j, &fd_master)) {
                                /* if client == listener, skip */
                                if (j != listener && j != i) {
                                    if (send(j, buf, bytes_recved, 0) == -1) {
                                        printf("send error: %s\n", strerror(errno));
                                    }
                                }
                            }
                        }
                        /* clear the buffer */
                        memset(&buf, 0, sizeof(buf));
                    }
                } /* end handle data from client */
            } /* end new connection */
        } /* end iterating through file descriptors */
    } /* end while main loop */

    return 0;
}
