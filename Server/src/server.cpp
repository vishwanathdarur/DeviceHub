#include "sys/socket.h"
#include "netinet/in.h"
#include "unistd.h"

#include <cerrno>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

#include "/home/vishwa/Project/DeviceHub/Server/include/server.hpp"

using namespace std;

Server::Server() {
    serverPort = 8080;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        throw runtime_error("Failed to create server socket");
    }

    int reuse = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    sockaddr_in serverAddress {};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(serverPort);

    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) < 0) {
        close(serverSocket);
        throw runtime_error(string("Failed to bind server socket: ") + strerror(errno));
    }

    if (listen(serverSocket, SOMAXCONN) < 0) {
        close(serverSocket);
        throw runtime_error(string("Failed to listen on server socket: ") + strerror(errno));
    }
}

void Server::ReceiveData() {
    cout << "DeviceHub demo server listening on port " << serverPort << '\n';

    while (true) {
        cout << "Waiting for a client connection..." << '\n';
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket < 0) {
            cerr << "Accept failed: " << strerror(errno) << '\n';
            continue;
        }

        char buffer[1024] = {0};
        ssize_t bytes = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0) {
            cerr << "Received empty payload or connection closed early" << '\n';
            close(clientSocket);
            continue;
        }

        string message(buffer, static_cast<size_t>(bytes));
        cout << "Received message: " << message << '\n';

        string response = "DeviceHub server acknowledged: " + message;
        send(clientSocket, response.c_str(), response.size(), 0);
        close(clientSocket);
    }
}


