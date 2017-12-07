#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include "Function_RunCounter.hpp"
using namespace std;

class logfile
{
	private:
		time_t now;               //required variables to get the current time
		char* time_now;
		fstream WriteLog;         //declaration of fstream object to write logs to a file
	public:
	    logfile(char filename[])   //class constructors
		{
			char count[3];
			snprintf(count,sizeof(count),"%d",ReadRunCounter());    //convert runcount to char
		   	now = time(0);
		   	time_now = ctime(&now);
		   	WriteLog.open(strcat(strcat(filename,count),".txt"),ios::out);  //open file to write log
		   	WriteLog<<"Run Time : "<<time_now;  // write to file
		   	WriteLog<<endl;
	    }
	    
	    void writeLog(char event[])   //function to write event logs to the file
	    {
	    	WriteLog<<event;
	    	WriteLog<<endl;
		}
		
		~logfile()      //desctructor
		{
			WriteLog.close();
		}
};

