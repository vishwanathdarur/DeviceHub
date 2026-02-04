#include "client.hpp"
#include <iostream>
#include <string>
#include "commonfunctions.hpp"
#include "clientfeature.hpp"
using namespace std;

int main() {
    Connection conn;
    if (!conn.hasuniqued()) {
        conn.createuniqueid();
    }
    string uniqueId = conn.readuniqueid();
    cout << "Your unique ID is: " << uniqueId << endl;
    ClientFeature feature;
    feature.loadmessage();  
    return 0;
}