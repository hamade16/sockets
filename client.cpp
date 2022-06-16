#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define PORT 8080

int main()
{
    int sd;
    struct sockaddr_in client_adr;
    const char *hello = "Hello from client";
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "client: erreur de creation d socket" << std::endl;
        exit(0);
    }
    /*demande de connection avec serveur*/
    memset(client_adr.sin_zero, '\0', sizeof(client_adr.sin_zero));
    client_adr.sin_family = AF_INET;
    client_adr.sin_addr.s_addr = INADDR_ANY;
    client_adr.sin_port = htons( PORT );
    if (connect(sd, (struct sockaddr *) & client_adr, sizeof(client_adr)) < 0)
    {
        std::cout << "connection failed" << std::endl;
        return (-1);
    }
    /*envoie un msg au serveur*/
    send(sd , hello , strlen(hello) , 0);
    std::cout << "Hello message sent" << std::endl;
}