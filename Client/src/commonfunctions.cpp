#include "commonfunctions.hpp"
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "client.hpp"
#include <iostream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

bool Connection::hasuniqued()
{
    std::string path = "Client/data/uniqueid/id.json";
    std::ifstream f(path);
    if (!f.is_open())
    {
        return false; // file doesn't exist
    }
    json j;
    try
    {
        f >> j;
    }
    catch (json::parse_error &)
    {
        cout << "JSON parse error" << endl;
        return false; // invalid or empty JSON
    }
    cout << j.dump() << endl;
    if(j["unique-id"]=="")
    {
        return false;
    }
    return true;
}

void Connection::createuniqueid() {
    // we are not  informed server yet
    
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;
    string uniqueId="00000001";
    string path="Client/data/uniqueid/id.json";
    ifstream f(path);
    json j;
    f>>j;
    j["unique-id"]=uniqueId;
    j["name"]=name; 
    ofstream o(path);   
    o << j.dump(4) << endl;
}

string Connection::readuniqueid() {
    string path = "Client/data/uniqueid/id.json";
    ifstream f(path);
    json j;
    f>>j;
    return j["unique-id"];
}






