#include <iostream>
#include <stdexcept>
#include <string>

#include "/home/vishwa/Project/DeviceHub/Client/include/client.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    string message = "Hello from DeviceHub demo client";
    if (argc > 1) {
        message = argv[1];
    }

    try {
        Client client;
        client.SendData(message);
        string response = client.receiveData();
        cout << "Client sent: " << message << '\n';
        cout << "Server replied: " << response << '\n';
        client.disconnect();
    } catch (const std::exception& ex) {
        cerr << "Client failed: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
