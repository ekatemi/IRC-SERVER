#ifndef IRCSERV_H
# define IRCSERV_H

# include <stdio.h>
# include <unistd.h>
#include <string>

class Ircserv
{

    private:
        int port;
        std::string password;
    public:
        Ircserv();
        Ircserv(int port, std::string password);
        Ircserv &operator=(const Ircserv &src);
        ~Ircserv();

        //methods
        
        Server(int port, std::string password);


};

#endif