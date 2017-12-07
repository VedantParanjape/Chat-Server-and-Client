#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include "Class_Logger.hpp"
using namespace std;


SOCKET ServerCom = INVALID_SOCKET;
int ClientAddressSize;
SOCKADDR_IN ClientAddress;
char lftxt[40] = "../Logs/ClientNetworkInitLogs";
logfile lf(lftxt);

class ClientNetworkInit
{
	private:
	    WSAData ClientNetworkData;
	    char message[512];

    public:
        ClientNetworkInit(char sIP[],u_short sPORT)
        {
        	lf.writeLog(sIP);
            cout<<"Intializing Winsock API";
			strcpy(lftxt,"Initializing Winsock API");
			lf.writeLog(lftxt);
			                                                                                                   
		    for(int i=0;i<15;i++)                                                                                                                
	   	    {
			  cout<<".";
			  Sleep(100);
		    }
		    if(!WSAStartup(MAKEWORD(2,1),(WSAData*)&ClientNetworkData))
		    {
		    	cout<<"done"<<endl;
		    	strcpy(lftxt,"done");
			    lf.writeLog(lftxt);
			}
			else
			{
				cout<<"Error starting Winsock API"<<endl;
				strcpy(lftxt,"Error starting Winsock API");
			    lf.writeLog(lftxt);
			    
			    cout<<"Shutting down the server"<<endl;
			    strcpy(lftxt,"Error starting Winsock API");
			    lf.writeLog(lftxt);
				lf.~logfile();
				
				closesocket(ServerCom);
	            WSACleanup();
	            exit(0);
			}
            
            ClientAddress.sin_addr.s_addr = inet_addr(sIP);
		    ClientAddress.sin_port = htons(sPORT);
		    ClientAddress.sin_family = AF_INET;
		    
		    ClientAddressSize = sizeof(ClientAddress);
		    ServerCom = socket(AF_INET,SOCK_STREAM,0);
		    
		    if(ServerCom == INVALID_SOCKET)
		    {
		        cout<<"Error initialising socket"<<endl;
		        strcpy(lftxt,"Error starting socket");
			    lf.writeLog(lftxt);
			    lf.~logfile();
				closesocket(ServerCom);
	            WSACleanup();
	            exit(0);
			}
			else
			{
				cout<<"Socket Intialised"<<endl;
				strcpy(lftxt,"Socket Intialised");
			    lf.writeLog(lftxt);
			}
		}
        void ConnectServer()
        {
            int val;
            val = connect(ServerCom,(SOCKADDR*)&ClientAddress,ClientAddressSize); 
            if(!val)
            {
               cout<<"Connected to server"<<endl;
               strcpy(lftxt,"Connected to server");
			   lf.writeLog(lftxt);
			} 
			   
		    else
		    {
		     cout<<"Unable to connect to the server"<<endl;	
		     strcpy(lftxt,"Unable to connect to the server");
			 lf.writeLog(lftxt);
			
		     cout<<"Closing chat client"<<endl;
		     strcpy(lftxt,"Closing chat client");
			 lf.writeLog(lftxt);
			 lf.~logfile();
			 
		     WSACleanup();
		     exit(0);
		    }
	    }
};
