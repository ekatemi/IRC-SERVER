#include "Client.hpp" //???


Client::Client() {
    if(connect (sockfd, (struct sockaddr *)&addr, addr_len) < 0)
    {

    }

}
Client::~Client(){
    close(sockfd);
}


/*toaddr contains the IP address and port number of the serve
addrlen is length of the socket address structure connect() returns 0 if connection is successful and -1 on error
*/