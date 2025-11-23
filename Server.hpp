#ifndef IRCSERV_H
# define IRCSERV_H

//# include <stdio.h>
# include <iostream>
# include <unistd.h>
#include <string>
#include <sys/socket.h>   // defines struct sockaddr
#include <netinet/in.h>
#include <exception>

//this are arguments TODO parse from input
#define PORT 4242 //1024–65535
#define PASSWORD "123"

//
class Server
{
    private:
        int sockfd; //fd
        int new_sockfd;
        struct sockaddr_in addr;
        struct sockaddr_in client_addr; //clients addr
        socklen_t addr_len;
        int backlog; //max connections from clients
        char buf[1024]; // not shure what for this
        int len;
    public:
        Server();
        
        ~Server();

};
#endif

/* A. Server

Stores global state:

server socket FD

list of client objects

list of channels

password

port

pollfd array

main loop

Handles:

new connections

reading data

parsing commands

routing to handlers */