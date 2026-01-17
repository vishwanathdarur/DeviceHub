#include <bits/stdc++.h>
#include "/home/vishwa/Project/DeviceHub/Client/include/client.hpp"
#include "/home/vishwa/Project/DeviceHub/Server/include/server.hpp"
#include "/home/vishwa/Project/DeviceHub/Server/include/commonfunctions.hpp"
#include "/home/vishwa/Project/DeviceHub/Server/include/connectdb.hpp"
using namespace std;

int main() {
    Server server;
    string key="0000000001";
    ConnectDB db;
    db.put(key,"TestUser");
    cout << db.get(key) << endl;
    return 0;
}
