#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include "Function_RunCounter.hpp"
using namespace std;

class logfile
{
	private:
		time_t now;
		char* time_now;
		fstream WriteLog;
	public:
	    logfile(char filename[])
		{
			char count[2];
			snprintf(count,sizeof(count),"%d",ReadRunCounter());
		   	now = time(0);
		   	time_now = ctime(&now);
		   	WriteLog.open(strcat(strcat(filename,count),".txt"),ios::out);
		   	WriteLog<<"Run Time : "<<time_now;
		   	WriteLog<<endl;
	    }
	    
	    void writeLog(char event[])
	    {
	    	WriteLog<<event;
	    	WriteLog<<endl;
		}
		
		~logfile()
		{
			WriteLog.close();
		}
};

