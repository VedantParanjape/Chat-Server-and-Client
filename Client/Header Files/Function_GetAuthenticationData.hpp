#include <iostream>
#include <string>
using namespace std;

void GetAuthenticationData(char msg[]);

void GetAuthenticationData(char msg[])
{
	string myid;
	string chatid;
	
	cout<<"Enter your ID: ";
	cin>>myid;
	
	cout<<"Enter the ID with whom you want to chat: ";
	cin>>chatid;
		
	myid = myid + chatid;
	
	strcpy(msg,myid.c_str());  
	
}
