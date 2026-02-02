#include "client.hpp"
#include <iostream>
#include <string>
#include "commonfunctions.hpp"
using namespace std;

int main() {
    Client client;
    client.SendData("Hello from Client the Server!");
    if(!Connection().hasuniqued()) {
        Connection().createuniqueid();
    }
    string uniqueid=Connection().readuniqueid();
    cout << "Unique ID: " << uniqueid << endl;
    string message="hey this from client";
    cout << message << endl;
    client.SendData("i am sending this message:");
    return 0;
}