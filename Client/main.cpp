#include <bits/stdc++.h>
#include "/home/vishwa/Project/DeviceHub/Client/include/client.hpp"
#include "/home/vishwa/Project/DeviceHub/Client/include/commonfunctions.hpp"
using namespace std;

int main() {
    Client client;
    if(!Connection().hasuniqued()) {
        Connection().createuniqueid();
    }
    string uniqueid=Connection().readuniqueid();
    cout << "Unique ID: " << uniqueid << endl;
    string message="hey this from client";
    client.SendData(uniqueid+message);
    return 0;
}