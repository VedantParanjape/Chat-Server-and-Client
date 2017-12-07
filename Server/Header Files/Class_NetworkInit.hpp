#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <process.h>
#include <thread>
#include <fstream>
#include <string>
#include <memory>
#include "Function_NetworkCom.hpp"
using namespace std;

////////////////////////////////// Variables //////   
int ClientStore = 0;                            //
char lftxtnio[40] = "../Logs/NetworkInitLogs"; // 
char lftxtni[50];                             //
logfile lfni(lftxtnio);                      //        
//////////////////////////////////////////////

///////////////////////////////////////// Class NetworkInit ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class NetworkInit 
{
private:
	//declarations of winsock library objects necessary for the sockets parts to run
	WSAData NetworkData;
    SOCKET ListenSocket;
    SOCKADDR_IN Address;
    int AddressSize; 
    
public:
	NetworkInit(); // default constructor
	
    NetworkInit(char IP[],u_short PORT) // argumented constructor
	{  
		lfni.writeLog(IP); // write server ip to log file
//---------------------------------------Initailize Winsock API----------------------------------------------------------------------------------------------------------------------------
		//process to start the winsock api
		
		strcpy(lftxtni,"Intializing Winsock API"); 
		lfni.writeLog(lftxtni);
		cout<<"Intializing Winsock API";                                                                           
		for(int i=0;i<17;i++)                                                                                                                
		{
			cout<<".";
			Sleep(100);
		}
		if(!WSAStartup(MAKEWORD(2,1),(WSAData*)&NetworkData))
		{
			cout<<"done"<<endl;
			strcpy(lftxtni,"done");
		    lfni.writeLog(lftxtni);
		}
		else
		{
			cout<<"Error starting Winsock API"<<endl;
			strcpy(lftxtni,"Error starting Winsock API");
		    lfni.writeLog(lftxtni);
		    
			cout<<"Shutting down the server"<<endl;
			strcpy(lftxtni,"Shutting down the server");
		    lfni.writeLog(lftxtni);
		    lfni.~logfile();
		    
			closesocket(ListenSocket);
			for(int i=0;i<10;i++)
			{
		    closesocket(ClientConn[i]);
		    }
	        WSACleanup();
	        exit(0);
		}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		Address.sin_addr.s_addr = inet_addr(IP);
		Address.sin_port = htons(PORT);
		Address.sin_family = AF_INET;
		
//---------------------------------------Binding Listening Socket--------------------------------------------------------------------------------------------------------------------------		
		//process of binding the socket
		
		cout<<"Binding socket";
		strcpy(lftxtni,"Binding socket");
		lfni.writeLog(lftxtni);
		for(int i=0;i<26;i++)
		{
			cout<<".";
			Sleep(50);
		}
		ListenSocket = socket(AF_INET,SOCK_STREAM,0);
		if(!bind(ListenSocket,(SOCKADDR*)&Address,sizeof(Address)))
		{
			cout<<"done"<<endl;
			strcpy(lftxtni,"done");
		    lfni.writeLog(lftxtni);
		}
		else
		{
			cout<<"Error Binding the port"<<endl;
			strcpy(lftxtni,"Error Binding the port");
		    lfni.writeLog(lftxtni);
		    
			cout<<"Shutting down the server"<<endl;
			strcpy(lftxtni,"Shutting down the server");
		    lfni.writeLog(lftxtni); // write to log file
		    lfni.~logfile();
		    
		   	closesocket(ListenSocket);
		   for(int i=0;i<10;i++)
			{
		    closesocket(ClientConn[i]);
		    }
	        WSACleanup();
	        exit(0);
		}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------Intialize listening socket------------------------------------------------------------------------------------------------------------------------		        
		//initialize the listening socket
		
		cout<<"Initializing listening socket";
		strcpy(lftxtni,"Initalizing listening socket");
		lfni.writeLog(lftxtni);
		
		for(int i=0;i<11;i++)
		{
			cout<<".";
			Sleep(100);
		}
		if(!listen(ListenSocket,SOMAXCONN))
		{
			cout<<"done"<<endl;
			strcpy(lftxtni,"done");
		    lfni.writeLog(lftxtni);
		}
		else
		{
			cout<<"Error in starting listening socket"<<endl;
            strcpy(lftxtni,"Error in starting listening socket");
		    lfni.writeLog(lftxtni);
		    
			cout<<"Shutting down the server"<<endl;
			strcpy(lftxtni,"Shutting down the server");
		    lfni.writeLog(lftxtni);
		    lfni.~logfile();
			closesocket(ListenSocket);
		    for(int i=0;i<10;i++)
			{
		    closesocket(ClientConn[i]);
		    }
	        WSACleanup();
	        exit(0);
		}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
		
		AddressSize = sizeof(Address);
		for(int i=0;i<10;i++)
		{
			ClientConn[i] = INVALID_SOCKET;
			ClientConn[i] = socket(AF_INET,SOCK_STREAM,0);
			
			if(ClientConn[i] == INVALID_SOCKET)
		    {
		        cout<<"Error in initialising  listening socket "<<i<<endl;
				strcpy(lftxtni,"Error in initialising  listening socket ");
		        lfni.writeLog(lftxtni);	
		        lfni.~logfile();
		    }			
		    else
	     	{
		    	cout<<"Socket intialized "<<i<<endl;
		    }			
	    	Sleep(200);
		}
	    
	    system("pause");
	    system("cls");
	
	    cout<<"\t\tTCP Chat Server_______v1.0______Vedant Paranjape"<<endl<<endl; // display of server information
		cout<<"\t\t----------------------------------------"<<endl;	
		cout<<"\t\t IP Address :"<<IP<<endl;
		cout<<"\t\t Port Number:"<<PORT<<endl;
		cout<<"\t\t----------------------------------------"<<endl;
    }
//--------------------------------------------Intitalize all client handler sockets--------------------------------------------------------------------------------------------------------		
  
	void AcceptConn()
	{
		for(;;)
		{
	  	    if((ClientConn[ClientStore] = accept(ListenSocket,(SOCKADDR*)&Address,&AddressSize)))
	  		    {
					cout<<"Client connected "<<endl;  
					send(ClientConn[ClientStore],"Enter your id and id of client with whom you want to chat",57,0); // send necessary instructions to the client
					CreateClientThread(ClientStore); // call function to create new client managing thread
					ClientStore++;		  	//increment the client counter
				}
        }
    }
    
    ~NetworkInit()
    {
    	// destructor -- shutdown the winsock api, delete the socket object
    	for(int i=0;i<10;i++)
    	{
    		cout<<"Closing socket "<<i<<endl;
    		closesocket(ClientConn[i]);
		}
		cout<<"Shutting down Winsock API"<<endl;
		strcpy(lftxtni,"Shutting down Winsock API");
		lfni.writeLog(lftxtni);
		lfni.~logfile();
		
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
