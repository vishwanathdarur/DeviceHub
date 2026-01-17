#include<iostream>
#include<string>
#include "/home/vishwa/Project/MiniVaultDB/include/db/db.hpp"
#include "/home/vishwa/Project/DeviceHub/Server/include/connectdb.hpp"

using namespace std;


ConnectDB::ConnectDB():db("devicehubdb",64*1024*1024) {
    
}
void ConnectDB::put(string key, string value) {
    db.put(key, value);
}

string ConnectDB::get(string key) {
    return db.get(key);
}

void ConnectDB::del(string key) {
    db.del(key);
}

bool ConnectDB::exists(string key) {
    return db.get(key) != "";
}