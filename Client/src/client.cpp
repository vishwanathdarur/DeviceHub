#include <iostream>
#include <string>
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "/home/vishwa/Project/DeviceHub/Client/include/client.hpp"
using namespace std;

Client::Client() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
}

void Client::SendData(const string& data) {
    send(clientSocket, data.c_str(), data.size(), 0);
}

std::string Client::receiveData() {
    char buffer[1024] = {0};
    recv(clientSocket, buffer, 1024, 0);
    cout << "Received from server: " << buffer << endl;
    return std::string(buffer);
}
