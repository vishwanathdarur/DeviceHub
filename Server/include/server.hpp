#pragma once

using namespace std;

class Server {
public:
    Server();
    void ReceiveData();
    void SendData(const string& data);
    void StartServer();
    void StopServer();
private:
    int serverPort;
    int serverSocket;
};


