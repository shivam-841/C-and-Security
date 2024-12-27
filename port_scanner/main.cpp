#include<iostream>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<cstring>
#include<iomanip>

using namespace std;

bool isPortOpen(const char *ip, int port){
    int sock;
    struct sockaddr_in address; //structure which specify IPv4 address , usually stores address of a socket(both IP address and Port)

    sock = socket(AF_INET,SOCK_STREAM,0); //creates a socket using IPv4 address and TCP socket as for SOCK_STREAM and O is the protocol so it will automatically choose which will be TCP in this case
    if(sock<0){
        cerr<<"Socket Creation Failed!"<<endl;
        return false;
    }

    address.sin_family = AF_INET; //sets address family for the socket
    address.sin_addr.s_addr = inet_addr(ip); //sets IP address for the socket, inet_addr convers string into a 32 bit integer(uint32_t) taht can be used by sin_addr-s_addr
    address.sin_port = htons(port); //sets port number and htons(host to network short) convert the port number to network byte order ,as sin_port stroes port number(16-bit fields)

    int connectionStatus = connect(sock,(struct sockaddr*)&address, sizeof(address));
    close(sock);
    return (connectionStatus==0);
}

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

    for(int port = startPort; port <= endPort; ++port) {
        if(isPortOpen(targetIP,port)){
            cout<<left<<setw(10)<<port<<setw(15)<<"Open"<<endl;
        }
        else{
            cout<<left<<setw(10)<<port<<setw(15)<<"Open"<<endl;
        }
    }

    cout<<"\nPort scan complete."<<endl;
    return 0;
    
}