#include<iostream>
#include<fstream>
#include"clientfeature.hpp"
#include<json.hpp>
using namespace std;
using json = nlohmann::json;

void ClientFeature::displayMenu() {
    cout << "Welcome to our local Device Hub \n";
    cout << "Here your options \n";
    cout << "1. Show List of connecte dDevices\n 2.Send Message to the Device\n 3.Loadmessage\n";
    cout << "4. sendmedia\n 5.getmedia\n";
    cout << "Enter your choice \n";
}

void ClientFeature::listConnectedDevices() {
    cout << "List of connected devices are \n";
    string path="Client/data/chatdata/myusers.json";
    ifstream f(path);
    json j;
    f>>j;
    for (auto& element : j) {
        cout << "client number: " << element["serial-number"] <<  ", Name: " << element["name"] << "\n";
    }
}

void ClientFeature::sendmessageToDevice() {
    cout << "Enter your client Number \n";
    int num; cin >> num;
    cout << "Enter Your message \n";
    string message; cin >> message;
    string id="";
    string path="Client/data/chatdata/myusers.json";
    ifstream f(path);
    json j;
    f>>j;       
    for (auto& element : j) {
        if(element["serial-num"]==to_string(num))
        {
            id=element["unique-id"];
            break;
        }
    }
    cout << "Sending message to client with ID: " << id << "\n";
    // we got the id to send the message

    // receive a feedback from client regarding message

    // cout that server message either successfull or not
}


void ClientFeature::loadmessage() {
    cout << "Enter your client number \n";
    int num; cin >> num;
    cout << "Your messages are \n";
    // get a message from the client

    string path1="Client/data/chatdata/message.json";
    ifstream file(path1);
    json j;
    file >> j;
    string path="Client/data/chatdata/myusers.json";
    ifstream f(path);
    json j2;
    f>>j2;
    string id="";
    for (auto& element : j2) {
        cout << element["serial-num"] << "\n";
        if(element["serial-num"]==to_string(num))
        {
            id=element["unique-id"];   
            break;
        }
    }   
    cout << id << "\n";
    if (j.contains(id))
    {
        json userData = j[id]; // directly access the unique ID
        for (auto &msg : userData["messages"])
        {
            std::cout << msg["message"] << " | "
                      << msg["date"] << " " << msg["time"] << " | "
                      << msg["status"] <<  " | Sent by: " << msg["sent-by"] << "\n";
        }
    }
}


 

void ClientFeature::sendmedia()  {
    cout << "Enter your client number \n";
    int num; cin >> num;
    cout << "Enter your path of the media (only pdf and images allowed) \n";
    string path; cin >> path;

    // from that get the path 

    // send to the server

    // get response regarding that and show to the user successful or not successfull
}


void ClientFeature::getmedia() {
    cout << "Enter the client number \n";
    int num; cin >> num;
    // check permission is allowed bw these clients

    // check is that client connected to a server

    cout << "Enter a path of path of media u want(only pdf and images are allowed) \n";
    string path; cin >> path;


    // get a files from a that specific user


    // save that file in a specific folder of a client


    // show the status
}