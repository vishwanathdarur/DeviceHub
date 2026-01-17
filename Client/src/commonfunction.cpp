#include <bits/stdc++.h>
#include "/home/vishwa/Project/DeviceHub/Client/include/commonfunctions.hpp"
#include "/home/vishwa/Project/DeviceHub/Client/include/client.hpp"

using namespace std;

bool Connection::hasuniqued() {
    FILE* f=fopen("/home/vishwa/Project/DeviceHub/Client/uniqueid.txt","r");
    if(f==NULL) return false;
    else {
        fclose(f);
        return true;
    }
}

void Connection::createuniqueid() {
    Client Client;
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;
    // Client.SendData(name);
    string uniqueid="0000000001";
    FILE* f=fopen("/home/vishwa/Project/DeviceHub/Client/uniqueid.txt","a");
    fprintf(f,"%s",uniqueid.c_str());
    fclose(f);   
}

string Connection::readuniqueid() {
    FILE* f=fopen("/home/vishwa/Project/DeviceHub/Client/uniqueid.txt","r");
    char buffer[100];
    fscanf(f,"%s",buffer);
    fclose(f);
    return string(buffer);
}

