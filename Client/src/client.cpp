#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

#include <client.hpp>

using namespace std;

Client::Client() : clientSocket(-1) {
    connectToServer("127.0.0.1", 8080);
}

void Client::connectToServer(const std::string& serverIP, int serverPort) {
    if (clientSocket != -1) {
        disconnect();
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        throw runtime_error("Failed to create client socket");
    }

    sockaddr_in serverAddress {};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);

    if (inet_pton(AF_INET, serverIP.c_str(), &serverAddress.sin_addr) <= 0) {
        close(clientSocket);
        clientSocket = -1;
        throw runtime_error("Invalid server IP address");
    }

    if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) < 0) {
        close(clientSocket);
        clientSocket = -1;
        throw runtime_error("Failed to connect to DeviceHub server");
    }
}

void Client::SendData(const string& data) {
    if (clientSocket < 0) {
        throw runtime_error("Client is not connected");
    }

    if (send(clientSocket, data.c_str(), data.size(), 0) < 0) {
        throw runtime_error("Failed to send data to server");
    }
}

std::string Client::receiveData() {
    if (clientSocket < 0) {
        throw runtime_error("Client is not connected");
    }

    char buffer[1024] = {0};
    ssize_t received = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (received <= 0) {
        return "";
    }

    return std::string(buffer, static_cast<size_t>(received));
}

void Client::disconnect() {
    if (clientSocket != -1) {
        close(clientSocket);
        clientSocket = -1;
    }
}

