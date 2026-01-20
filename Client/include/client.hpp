#pragma once
#include <string>

class Client {
public:
    Client();
    void connectToServer(const std::string& serverIP, int serverPort);
    void SendData(const std::string& data);
    std::string receiveData();
    void disconnect();
private:
    int clientSocket;
};  

