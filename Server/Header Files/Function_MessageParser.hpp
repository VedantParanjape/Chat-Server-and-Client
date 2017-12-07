#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct AuthDataParsed
{
	int ID;
	int sID;
}; 

void AuthDataParser(char RawMessage[],AuthDataParsed& msg);

void AuthDataParser(char RawMessage[],AuthDataParsed& msg)
{
	char id[3] = "";
	char sid[3] = "";
	
	for(int i=0;i<2;i++)
	{
		id[i] = RawMessage[i];
	}
	
	for(int i=0;i<2;i++)
	{
		sid[i] = RawMessage[i+2];
	}
	
	msg.ID = atoi(id);
	msg.sID = atoi(sid);
	
}




