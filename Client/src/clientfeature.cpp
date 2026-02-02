#include<iostream>
using namespace std;

void ClientFeature::displayMenu() {
    cout << "Welcome to our local Device Hub \n";
    cout << "Here your options \n";
    cout << "1. Show List of connecte dDevices\n 2.Send Message to the Device\n 3.Loadmessage\n";
    cout << "4. sendmedia\n 5.getmedia\n";
    cout << "Enter your choice \n";
}

void ClientFeature::listConnectedDevices() {
    cout << "Your connected devices are ";
    // send a request to server for devices

    // receive from server and display
}

void ClientFeature::sendmessageToDevice() {
    cout << "Enter your client Number \n";
    int num; cin >> num;
    cout << "Enter Your message \n";
    string message; cin >> message;


    // send this message this to  the client


    // receive a feedback from client regarding message
    // cout that server message either successfull or not
}


void ClientFeature::loadmessage() {
    cout << "Enter your client number \n";
    int num; cin >> num;
    cout << "Your messages are \n";
    // get a message from the client
    
    // display the messages
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