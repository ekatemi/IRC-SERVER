#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <stdio.h>
# include <unistd.h>
#include <string>
#include <sys/socket.h>   // defines struct sockaddr
#include <netinet/in.h>
#include <exception>


class Client {
    private:
    int sockfd; //fd
    struct sockaddr_in addr;
    socklen_t addr_len;

    public:
    Client();
    ~Client();
};

#endif