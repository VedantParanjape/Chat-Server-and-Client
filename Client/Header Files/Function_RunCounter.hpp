#include <iostream>
#include <fstream>
using namespace std;

int ReadRunCounter();
void WriteRunCounter();

int ReadRunCounter()
{
	int counter;
	fstream file;
	file.open("../Logs/RunCounter.txt",ios::in);
	
	file>>counter;
	file.close();
	return counter;
}

void WriteRunCounter()
{
	int tempcount = ReadRunCounter();
	tempcount++;
	
	fstream fileWrite;
	fileWrite.open("../Logs/RunCounter.txt",ios::out);
	
	fileWrite<<tempcount;
	fileWrite.close();
}
