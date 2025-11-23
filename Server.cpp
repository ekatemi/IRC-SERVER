#include "Server.hpp"


Server::Server() {

    backlog = 5;
    addr_len = sizeof(client_addr);
    //create socket
    //domain AF_INET for Ipv4 AF_INET6 for Ipv6
    //type SOCK_STREAM for TCP
    //protocol 0
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) //domain type protocol
    {
        throw std::runtime_error("socket() failed: " + std::string(strerror(errno)));
    }


    //fill struct sockaddr_in AF_INET for Ipv4 AF_INET6 for Ipv6
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4242); //Host To Network Short (Host → сеть, 16 бит)
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //bind to port 4242
    //do I neet to know fd of bind?
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw std::runtime_error("bind() failed: " + std::string(strerror(errno)));
    }

    if(listen(sockfd, backlog) < 0) {
        throw std::runtime_error("listen() failed: " + std::string(strerror(errno)));
    }

    std::cout << "Server listening on port 4242" << std::endl;
    
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
    if(new_sockfd  < 0) {
        throw std::runtime_error("accept() failed: " + std::string(strerror(errno)));
    }
    std::cout << "Client connected!" << std::endl;
    //read recieve msg
    len = read(new_sockfd, buf, sizeof(buf)-1);
    if(len < 0) {
        throw std::runtime_error("read() failed: " + std::string(strerror(errno)));
    }
    
    buf[len] = '\0';
    std::cout << "Received: " << buf << std::endl;


}
        
Server::~Server() {
    close(sockfd);
}