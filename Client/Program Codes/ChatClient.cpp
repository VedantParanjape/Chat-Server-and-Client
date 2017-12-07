#include <iostream>
#include <thread>
#include "../Header files/Class_ClientNetworkInit.hpp"
#include "../Header files/Function_ClientNetworkCom.hpp"
using namespace std;

main()
{
	WriteRunCounter();             //updates the counter which counts the number of times this program is run
    char ip[15];                   //variable to store the ip address
    u_short port;
    thread recv;
    
    cout<<"\t\tChat Client v1.0_Alpha <====> Client"<<endl;
    
	cout<<"Enter the ip address of the server: ";
    cin>>ip;
    
    cout<<"Enter the port of the server: ";
    cin>>port;
    
    ClientNetworkInit cli(ip,port);         //construct the ClientNetworkInit object
    cli.ConnectServer();                    //connect to the specified server
    
    ClientNetworkComInit(ip,port);         //setup to enter your id and the id of the user you want to chat with
     
	recv = thread(ClientNetworkComRecv);    //start the reciever on  a separate thread
    recv.detach();
    
    ClientNetworkComSend();                //run the sender in the main thread
}
