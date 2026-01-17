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
