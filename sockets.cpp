#include "sockets.hpp"

sockets::sockets() : fd(-1)
{
    memset(adress.sin_zero, '\0', sizeof(adress.sin_zero));
}

sockets::sockets(int domaine, int type, int protocole)
{
    memset(adress.sin_zero, '\0', sizeof(adress.sin_zero));
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "server: erreur de creation d socket" << std::endl;
        exit(0);
    }
}

void    sockets::setadress()
{
    adress.sin_family = AF_INET;
    adress.sin_addr.s_addr = INADDR_ANY;
    adress.sin_port = htons( PORT );
}

void sockets::my_bind()
{
    if ((bind(fd, (struct sockaddr*) & adress, sizeof(struct sockaddr))) < 0)
    {
        std::cout << "serveur: erreur in socket" << std::endl;
        exit(0);
    }
}
void sockets::my_listen(int backlog)
{
     if (listen(fd, backlog) < 0)
    {
        std::cout << "srveur:erreur au niveau de l'ecoute" << std::endl;
        exit(0);
    }
}

void sockets::my_accept()
{
    int addrlen = sizeof(adress);

    if ((accept_fd = accept(fd, (struct sockaddr *) & adress, (socklen_t*)&addrlen)) < 0)
    {
        std::cout << "serveur: erreur d'acceptation" << std::endl;
        exit(0);
    }
}
void   sockets::my_recv()
{
    char buf[1024];
    int buf_len;
    if ((buf_len = recv(accept_fd, buf, 1024, 0)) < 0)
    {
        std::cout << "serveur: erreur de lecture du msg recu " << std::endl;
        exit(0);
    }
}

void    sockets::my_connect()
{
    if (connect(fd, (struct sockaddr *) & adress, sizeof(adress)) < 0)
    {
        std::cout << "connection failed" << std::endl;
        exit(0);
    }
}

void    sockets::my_send()
{
     const char *hello = "Hello from client";

    send(fd , hello , strlen(hello) , 0);
    std::cout << "Hello message sent" << std::endl;
}

sockets::~sockets()
{

}