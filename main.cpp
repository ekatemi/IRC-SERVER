#include "Server.hpp"
#include <iostream>

int main(int argc, char **argv) //port pswd
{
    if(argc != 3)
        return 1;
    int port = atoi(argv[1]);
    std::string pswd = argv[2];
    try {
        Server serv(port, pswd);
        serv.run();
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }

    return 0;
}
