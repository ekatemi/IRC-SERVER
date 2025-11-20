#include "ircserv.hpp"

int main(int argc, char **argv)
{
    if(srgc != 3)
        std::cout << "Wrong args! Input should be " << std::endl;
    
    try {
        
        Ircserv serv(argv[1], argv[2]);
    }
    catch


    return 0;
}