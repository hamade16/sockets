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

class sockets
{
    private:
        struct sockaddr_in adress;
        int fd;
    public:
        sockets();
        sockets(int domaine, int type, int protocole);
        ~sockets();


        int     bind();
        void    setadress(short family, unsigned short in_port, struct in_addr s_addr);
        void     listen(int backlog);
        sockets  accept();

};


#endif