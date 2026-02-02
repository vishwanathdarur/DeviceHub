#pragma once
#include </home/vishwa/Project/MiniVaultDB/include/db/db.hpp>
#include <string>
using namespace std;
class ConnectDB {
private:
    
public:
    ConnectDB();
    void put(string key, string value);
    string get(string key);
    void del(string key);
    bool exists(string key);
    mvdb::DB db;
};