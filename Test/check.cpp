#include <iostream>
#include <stdexcept>

#include "/home/vishwa/Project/DeviceHub/Server/include/server.hpp"

int main() {
    try {
        Server server;
        server.ReceiveData();
    } catch (const std::exception& ex) {
        std::cerr << "Server failed: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
