#include "sockets.hpp"
int main()
{
    sockets sock_cl(AF_INET, SOCK_STREAM, 0);
    sock_cl.setadress();
    sock_cl.my_connect();
    sock_cl.my_send();


    /*
    int sd;
    struct sockaddr_in client_adr;
    const char *hello = "Hello from client";
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "client: erreur de creation d socket" << std::endl;
        exit(0);
    }
    demande de connection avec serveur
    memset(client_adr.sin_zero, '\0', sizeof(client_adr.sin_zero));
    client_adr.sin_family = AF_INET;
    client_adr.sin_addr.s_addr = INADDR_ANY;
    client_adr.sin_port = htons( PORT );
    if (connect(sd, (struct sockaddr *) & client_adr, sizeof(client_adr)) < 0)
    {
        std::cout << "connection failed" << std::endl;
        return (-1);
    }
    envoie un msg au serveur
    send(sd , hello , strlen(hello) , 0);
    std::cout << "Hello message sent" << std::endl;*/
    return (0);

}