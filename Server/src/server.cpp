#include <iostream>
#include <string>
#include "sys/socket.h"
#include "netinet/in.h"
#include "/home/vishwa/Project/DeviceHub/Server/include/server.hpp"

using namespace std;    

Server::Server() {
    serverPort = 8080;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(serverPort); 
    bind(serverSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
    listen(serverSocket,SOMAXCONN);
}

void Server::ReceiveData() {
    while(true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        char buffer[1024] = {0};
        recv(clientSocket, buffer, 1024, 0);
        
    }
}


