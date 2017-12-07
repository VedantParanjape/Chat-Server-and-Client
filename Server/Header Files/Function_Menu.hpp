#include <iostream>
#include <process.h>
using namespace std;

int Menu();
int Menu()
{
	int option; //define option variable
	system("cls"); //clear the screen 
	cout<<"\t\tTCP Chat Server_______v1.0______Vedant Paranjape"<<endl<<endl;
	cout<<"\t\t\t<---::Menu::--->"<<endl;
	cout<<"\t\t\t _________________   "<<endl;
	cout<<"\t\t\t| 1. Start Server |  "<<endl;
	cout<<"\t\t\t| 2. About        |  "<<endl;
	cout<<"\t\t\t| 3. Help         |  "<<endl;
	cout<<"\t\t\t| 4. Quit         |  "<<endl;
	cout<<"\t\t\t|_________________|  "<<endl;
	cout<<"\t\t\tOption: ";
	cin>>option;  //take the input of option
	cin.ignore(); 
	
	return option;
}
