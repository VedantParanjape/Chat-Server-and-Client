#include <iostream>
using namespace std;

//////////////////////
int ID_Array[10];  //
////////////////////

/////////////////////////////////////////
void IDStore(int ID,int ArrayLoc);    //
void IDStore(int ID,int ArrayLoc)    //
{                                   //
	ID_Array[ArrayLoc] = ID;       // 
}                                 //
///////////////////////////////////

///////////////////////////////////////
int IDReturn(int ArrayLoc);         //
int IDReturn(int ArrayLoc)         //
{                                 //
	return ID_Array[ArrayLoc];   //
}                               //
/////////////////////////////////

//////////////////////////////////////////////
int ReturnLocation(int ID);                //
int ReturnLocation(int ID)                //
{                                        //
	int lo = 0;                         //
	                                   //
	for(int i=0;i<10;i++)             //
	{                                //
		if(ID_Array[i] == ID)       //
		{                          //
			lo = i;               //
		}                        //
		                        //
	}                          //
	return lo;                //	
}                            //
//////////////////////////////
