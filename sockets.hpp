#ifndef SOCKETS_HPP
# define SOCKETS_HPP

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <poll.h>

#define PORT 8080

class sockets
{
    private:
        struct sockaddr_in adress;
        int fd;
        int accept_fd;

    public:
        sockets();
        sockets(int domaine, int type, int protocole);
        ~sockets();


        void     my_bind();
        void    setadress();
        void     my_listen(int backlog);
        void    my_accept();
        void    my_recv();
        void    my_connect();
        void    my_send();
};


#endif