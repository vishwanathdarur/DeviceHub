#pragma once
#include <string>
#include <vector>
using namespace std;

class Connection {
public:
    bool validconnection(string key);
    void removeconnection(string key);
    void assignuniqueid(string username);
    vector<pair<int,string>> getidslist();    
    string decimaltoBinary(int n);
    int binarytoDecimal(string n);   
    vector<string> getchatlist(string key);
    string exractmessage(string data);
    bool checkvalidmessage(string data);
    vector<string> loadmessages(string key);
private:
    int totalclients=0;
};