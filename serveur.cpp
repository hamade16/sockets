#include "sockets.hpp"

#define PORT 8080
int main(int ac, char **av)
{
    sockets sock(AF_INET, SOCK_STREAM, 0);
    sock.setadress();
    sock.my_bind();
    sock.my_listen(10);
    while (1)
    {
        std::cout << std::endl;
        std::cout << "+++++++ Waiting for new connection ++++++++" << std::endl;
        std::cout << std::endl;
        sock.my_accept();
        sock.my_recv();
         std::cout << "hamade" << std::endl;
    }

    /*
    int ss;
    int sock_dis;
    struct sockaddr_in serveur_adr;
    int addrlen = sizeof(serveur_adr);
    struct pollfd mypoll;

    create socket
    if ((ss = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "server: erreur de creation d socket" << std::endl;
        exit(0);
    }
    bind: donee un adress et un port a notre socket
    serveur_adr.sin_family = AF_INET;
    serveur_adr.sin_addr.s_addr = INADDR_ANY;
    serveur_adr.sin_port = htons( PORT );
    memset(serveur_adr.sin_zero, '\0', sizeof(serveur_adr.sin_zero));
    if ((bind(ss, (struct sockaddr*) & serveur_adr, sizeof(struct sockaddr))) < 0)
    {
        std::cout << "serveur: erreur in socket" << std::endl;
        exit(0);
    }
    listen: attente des clients
    if (listen(ss, 10) < 0)
    {
        std::cout << "srveur:erreur au niveau de l'ecoute" << std::endl;
        exit(0);
    }
    memset(&mypoll, 0, sizeof(mypoll));
    mypoll.fd = 0;
    mypoll.events = POLLIN;
    accept: accepter une demande de conexion
    while (1)
    {
        std::cout << std::endl;
        std::cout << "+++++++ Waiting for new connection ++++++++" << std::endl;
        std::cout << std::endl;
        if ((sock_dis = accept(ss, (struct sockaddr *) & serveur_adr, (socklen_t*)&addrlen)) < 0)
        {
            std::cout << "serveur: erreur d'acceptation" << std::endl;
            exit(0);
        }
        recev: recuperer les donnes du client
        char buf[1024];
        int buf_len;
        if ((buf_len = recv(sock_dis, buf, 1024, 0)) < 0)
        {
            std::cout << "serveur: erreur de lecture du msg recu " << std::endl;
            exit(0);
        }
        std::cout << "hamade" << std::endl;

    }
*/
}