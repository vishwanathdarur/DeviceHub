#include <iostream>
#include <string>
#include "/home/vishwa/Project/DeviceHub/Server/include/commonfunctions.hpp"
#include "/home/vishwa/Project/DeviceHub/Server/include/connectdb.hpp"

using namespace std;


string Connection::decimaltoBinary(int n) {
    string result = "";
    for (int i = 0; i < 10; i++) {
        result = to_string(n % 2) + result;
        n /= 2;
    }
    return result;
}

int Connection::binarytoDecimal(string n) {
    int result = 0;
    for (int i = 0; i < n.size(); i++) {
        result = result * 2 + (n[i] - '0');
    }
    return result;
}

void Connection::assignuniqueid(string username) {
    Connection::totalclients++;
    string uniqueid = decimaltoBinary(totalclients);
    ConnectDB db;
    db.put(uniqueid, username);
}

bool Connection::validconnection(string key) {
    ConnectDB db;
    return db.exists(key);
}

vector<pair<int,string>> Connection::getidslist() {
    ConnectDB db;
    vector<pair<int,string>> ids;

    for (int i = 1; i <= totalclients; i++) {
        string id = decimaltoBinary(i);
        ids.push_back({i, db.get(id)});
    }
    return ids;
}

string Connection::exractmessage(string data) {
    string z = "";
    for (int i = 63; i < data.size(); i++) {
        z += data[i];
    }
    return z;
}

void Connection::decryptmessages(string key) {
    //1. sending clint id pref="10100101"
    //2. sending clint the list of clients available to chat with pref="10100110"
    //3. loading clint-clint message history pref="10100111"
    //4. saving the client message
    string z="";
    for(int i=0;i<8;i++) {
        z+=key[i];
    }
    if(z=="10100101") {
        //send client id
    } else if(z=="10100110") {
        //send client the list of clients available to chat with
    } else if(z=="10100111") {
        //load client-client message history
    } else {
        string key1=key.substr(0,63);
        string message="";
        for(int i=63;i<key.size();i++) {
            message+=key[i];
        }
        ConnectDB db;
        db.put(key,message);
    }
}