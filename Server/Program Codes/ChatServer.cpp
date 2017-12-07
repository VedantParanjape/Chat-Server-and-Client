#include <iostream>
#include <process.h>
#include <conio.h>
#include "../Header Files/Function_Menu.hpp"
#include "../Header Files/Class_NetworkInit.hpp"
using namespace std;

void CommandHandle(NetworkInit& a);

void CommandHandle(NetworkInit& a)
{
	char command[5];
	
	cin.ignore();
	
	while(1)
	{
		if(kbhit())
		{
			cin.getline(command,20);
		}
		
		if(!strcmp(command,"quit"))
		{
			a.~NetworkInit();
			break;
		}
	}
}

void RunServer();

void RunServer()
{
	WriteRunCounter();
	char IP[16];
    u_short PORT;
    thread CommandHandler;

    system("cls");
	cout<<"\n\n\t\tEnter the server ip address: ";
  	cin>>IP;
    cout<<endl;
    			
    cout<<"\t\tEnter the server port: ";
    cin>>PORT;
    cout<<endl;
    			
    			
    NetworkInit com(IP,PORT);
    
    CommandHandler = thread(CommandHandle,ref(com));
    com.AcceptConn();
}

void about();

void about()
{
	system("cls");
	cout<<"Made By: Vedant Paranjape"<<endl;
	cout<<"TCP Chat Server"<<endl;
	cout<<"Version: 1.0(alpha)"<<endl;
	cout<<"Made for class XII Computer Science project"<<endl;
	system("pause");
}

void help();

void help()
{
	system("cls");
	cout<<"Press 1 to start server"<<endl;
	cout<<"Then enter the ip address on which the server should be accessible...it should be your PC's local ip or 127.0.0.1 for localhost"<<endl;
	cout<<"After that enter the port on which it should work"<<endl;
	cout<<"Now the Server is setup and now clients can connect"<<endl;
	cout<<"Check the documentation for more details..."<<endl;
	system("pause");
}
main()
{
	do
	{
		switch(Menu())
		{
			case 1:
				RunServer();
				break;
				
				case 2:
					about();
					break;
					
					case 3:
						help();
						break;
						
						case 4:
							exit(0);
							break;
		}
	}while(1);
}
