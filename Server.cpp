#include "Server.hpp"

//only check args and init variables
Server::Server(int port, const std::string &password)
    : _port(port),
      _password(password),
      sockfd(-1),
      new_sockfd(-1),
      backlog(10),      // max clients????
      len(0)
{
    // валидация                                    TODO add checkings
    if (port <= 0 || port > 65535)
        throw std::runtime_error("Invalid port");
    if (password.empty())
        throw std::runtime_error("Empty password");

    // обнуление структур
    memset(&addr, 0, sizeof(addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // можно настроить длину структуры клиента сразу
    addr_len = sizeof(client_addr);

    // очистка буфера
    memset(buf, 0, sizeof(buf));
}

void Server::start() {
    /*---------------------------------------------------------------------*/
    /*create socket                                                        */
    /*---------------------------------------------------------------------*/
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) //domain type protocol
    {
        throw std::runtime_error("socket() failed: " + std::string(strerror(errno)));
    }

    /*---------------------------------------------------------------------*/
    /*fill struct sockaddr_in AF_INET for Ipv4 AF_INET6 for Ipv6           */
    /*---------------------------------------------------------------------*/
    //domain AF_INET for Ipv4 AF_INET6 for Ipv6
    //type SOCK_STREAM for TCP
    //protocol 0
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port); //Host To Network Short (Host → сеть, 16 бит)
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    /*---------------------------------------------------------------------*/
    /*              bind to port 4242                                      */
    /*---------------------------------------------------------------------*/
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw std::runtime_error("bind() failed: " + std::string(strerror(errno)));
    }
    /*---------------------------------------------------------------------*/
    /*              listening                                              */
    /*---------------------------------------------------------------------*/
    if(listen(sockfd, backlog) < 0) {
        throw std::runtime_error("listen() failed: " + std::string(strerror(errno)));
    }

    std::cout << "Server listening on port 4242" << std::endl;
}

int Server::acceptClient() {
    /*---------------------------------------------------------------------*/
    /*              accept                                             */
    /*---------------------------------------------------------------------*/
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
    if(new_sockfd  < 0) {
        throw std::runtime_error("accept() failed: " + std::string(strerror(errno)));
    }
    std::cout << "Client connected!" << std::endl;
    return new_sockfd;
}

void Server::handleClient() {
    /*---------------------------------------------------------------------*/
    /*              read recieve msg                                       */
    /*---------------------------------------------------------------------*/
    len = read(new_sockfd, buf, sizeof(buf)-1);
    if(len < 0) {
        throw std::runtime_error("read() failed: " + std::string(strerror(errno)));
    }
    buf[len] = '\0';
    std::cout << "Received: " << buf << std::endl;

}

void Server::run() {
    start();
    while(true) {
        acceptClient();
        handleClient();
        close(new_sockfd);
    }
}
        
Server::~Server() {
    close(sockfd);
}