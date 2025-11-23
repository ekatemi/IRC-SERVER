#include "Server.hpp"
#include <iostream>

int main(void)
{
    try {
        Server serv;   // <-- правильно
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }

    return 0;
}
