#include <iostream>
#include <string>
#include "sys/socket.h"
#include "netinet/in.h"
#include "/home/vishwa/Project/DeviceHub/Server/include/server.hpp"
#include <omp.h>
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
    #pragma omp parallel num_threads(1)
    {
        while (true) {
            int n=0;
            int thread_id = omp_get_thread_num();
            cout << "Thread " << thread_id << " waiting for connection...\n";
            int clientSocket = accept(serverSocket, nullptr, nullptr);
            while(true) {
                n++;
                if(n>=10) break;
                char buffer[1024] = {0};
                ssize_t bytes = recv(clientSocket, buffer, sizeof(buffer), 0);
                cout << "Thread " << thread_id << " received: " << string(buffer, bytes) << endl;
            }
        }
    }
}


