#include "Server.hpp"
#include <iostream>

int main(int argc, char **argv) //port pswd
{
    try {
        Server serv(argv[0], argv[1]);
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
