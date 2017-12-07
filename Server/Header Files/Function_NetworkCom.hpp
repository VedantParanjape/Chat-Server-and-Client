#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <winsock2.h>
#include <windows.h>
#include "Library_IDManager.hpp"
#include "Function_MessageParser.hpp"
#include "Class_Logger.hpp"
using namespace std;

////////// variables ////////////                      
thread HandleClient[10]; 
SOCKET ClientConn[10];
char lftxt[20] = "../Logs/ChatLogs";
logfile lf(lftxt);
/////////////////////////////

////////////////////////////////////////////////// Function NetworkCom //////////////////////////////////////////////////////////////////////////////////////////////////
void NetworkCom(int loc);   

void NetworkCom(int loc)
{
	int flag = 0;
    char datatemp[512] = " ";
    char msgtemp[512] = " ";
    AuthDataParsed AuthData;
    
	do
	{
		flag = recv(ClientConn[loc],datatemp,512,0);
	}while(flag<=0);
	flag = 0;
	
	AuthDataParser(datatemp,AuthData);
	IDStore(AuthData.ID,loc);
	
	cout<<">>"<<"ID # "<<AuthData.ID<<" sID # "<<AuthData.sID<<endl;
	
	while(ClientConn[loc] != INVALID_SOCKET)
	{  
	    flag = recv(ClientConn[loc],msgtemp,512,0);
	    if(flag > 0)
	    {
		   lf.writeLog(datatemp);
	       lf.writeLog(msgtemp);
	    }
	    flag = 0;
	    
		flag = send(ClientConn[ReturnLocation(AuthData.sID)],msgtemp,512,0);
		if(flag > 0)
		{
		   lf.writeLog(datatemp);
	       lf.writeLog(msgtemp);
	    }
	    flag = 0;
	    
		if(!strcmp(msgtemp,"EXIT"))
		{
			closesocket(ClientConn[loc]);
			cout<<"Client "<<AuthData.ID<<" has disconnected"<<endl;
			cout<<"Client "<<AuthData.sID<<" has disconnected"<<endl;
			break;
		}
	}
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////// Function CreateClientThread ///////////////////////////////////////////////////////////////////////////////////////
void CreateClientThread(int location);

void CreateClientThread(int location)
{
   	HandleClient[location] = thread(NetworkCom,location);
   	HandleClient[location].detach();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


