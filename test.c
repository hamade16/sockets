#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>


int main()
{
    char name[255];
    int counter;
    struct pollfd mypoll;
    memset(&mypoll, 0, sizeof(mypoll));
    mypoll.fd = 0;
    mypoll.events = POLLIN;

    printf("type in your name:\n");
    while (1)
    {
        if (poll(&mypoll, 1, 100) == 1){
            read(0, name, sizeof(name));
            printf("hello, %s\n", name);
            break;
        }
        else
            printf ("hamade\n");
          //  counter++;
    }
    printf("it took you %d ms to type in your name\n", 100 * counter);
    return (0);
}