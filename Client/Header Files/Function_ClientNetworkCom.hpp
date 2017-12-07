#include <iostream>
#include <string>
#include "Function_GetAuthenticationData.hpp"
using namespace std;

struct chatData
{
	int myid;
	int chatid;
};

void DataExt(char msg[],chatData& data)
{
   char tmp[3];
   char tmp0[3];
   
   for(int i=0;i<2;i++)
   {
       tmp[i] = msg[i];	
   }
   for(int i=0;i<2;i++)
   {
       tmp0[i] = msg[i+2];	
   }
   
   data.myid = atoi(tmp);
   data.chatid = atoi(tmp0);	
} 
 
void ClientNetworkComInit(char ip[],u_short port)
{
	string cMessageRecv;
	char cMessage[512] = " ";
    int cstate = 0;
    chatData data;
    
    do
    {
    	cstate = recv(ServerCom,cMessage,512,0);
	}while(cstate <=0);
	cMessageRecv = cMessage;
	cout<<"Command: "<<cMessageRecv<<"(the id can be from 10-99 only)"<<endl;
	cstate = 0;
	strcpy(cMessage," ");
	
	GetAuthenticationData(cMessage);
	cin.ignore();

	do
    {
    	cstate = send(ServerCom,cMessage,512,0);
	}while(cstate <=0);
	cstate = 0;

    DataExt(cMessage,data);
    
	system("cls");
	
	cout<<"\t\tChat Client v1.0_Alpha"<<endl;
	cout<<"Connected to: "<<ip<<"@"<<port<<" Chat ID: "<<data.myid<<" Chatting with ID: "<<data.chatid<<endl;
	cout<<"To quit chat type EXIT"<<endl<<endl;
}

//call this in a thread
void ClientNetworkComSend()
{
	char MessageSend[512] = " ";
	int mstate = 0;
	
	while(strcmp(MessageSend,"EXIT"))
	{
	    cin.getline(MessageSend,512);
	 do
	 {
		mstate = send(ServerCom,MessageSend,512,0);
	 }while(mstate<=0);
    }
    exit(0);
}

// call this is separate thread
void ClientNetworkComRecv()
{
	string cMessageRecv;
	char cMessageRcv[512] = "";
	int flag = 0;

	while(strcmp(cMessageRcv,"EXIT"))
	{
		do
		{
			flag = recv(ServerCom,cMessageRcv,512,0);
		}while(flag<=0);
		
		cMessageRecv = cMessageRcv;
		cout<<"\t\t\t\t\t\t"<<cMessageRecv<<endl;
	}
	exit(0);	
}
