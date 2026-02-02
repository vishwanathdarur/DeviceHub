#include <bits/stdc++.h>
#include "/home/vishwa/Project/DeviceHub/Client/include/client.hpp"
#include "/home/vishwa/Project/DeviceHub/Server/include/server.hpp"

using namespace std;
int main() {
    Client client;
    string message = "Hello from Client to Server!";
    client.SendData(message);
    return 0;
}