#include<iostream>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<cstring>
#include<iomanip>

using namespace std;



int main(){
    char targetIP[20];
    int startPort, endPort;

    cout<<"===========Simple Port Scanner=============="<<endl;
    cout<<"Enter Target IP Address: ";
    cin>>targetIP;
    cout<<"Enter Start Port: ";
    cin>>startPort;
    cout<<"Enter End Port: ";
    cin>>endPort;

    if(startPort>endPort || startPort<0 || endPort>65535){
        cerr<<"Invalid port range!"<<endl;
        return 1;
    }

    cout<<"\nScanning IP: "<<targetIP<<" on ports "<<startPort<<" to "<<endPort<<"...\n"<<endl;

    cout<<left<<setw(10)<<"Port"<<setw(15)<<"Status"<<endl;
    cout<<"---------------------------------"<<endl;
    
}