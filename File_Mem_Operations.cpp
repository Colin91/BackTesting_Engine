#include "File_Mem_Operations.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include <math.h>
using namespace std;

//"Input Type : 0 - (Default) , 1 - (Indicators) , 2 - (Strategy) , 3 - (Parametization)"<<endl;
File_Mem_Operations::File_Mem_Operations(fstream* FP_Price_In,fstream* FP_Ind_In,int Type_In,int Index_In,Indicators IND_In,int Period_In)
{
	Price_File = FP_Price_In;
	Ind_File = FP_Ind_In;
	IND = IND_In;
	Period = Period_In;	
	FMO_SET_TYPE(Type_In);
}

File_Mem_Operations::~File_Mem_Operations()
{

}


void File_Mem_Operations::FMO_SET_TYPE(int Type_In)
{
			
	if(Type_In==0)
	{
		Type_I = Type_In;
		Type_S = "DEF";
		FMO_GET_SIZE_OF_FILE();
		FMO_SET_CHUNKS();
		FMO_OPERATION();
	}
	if(Type_In==1)
	{
		Type_I = Type_In;
		Type_S = "IND";
		FMO_GET_SIZE_OF_FILE();
		FMO_SET_CHUNKS();
		FMO_OPERATION();
	}
	if(Type_In==2)
	{
		Type_I = Type_In;
		Type_S = "STR";
		FMO_GET_SIZE_OF_FILE();
		FMO_SET_CHUNKS();
		FMO_OPERATION();
	}
	if(Type_In==3)
	{
		Type_I = Type_In;
		Type_S = "PRM";
		FMO_GET_SIZE_OF_FILE();
		FMO_SET_CHUNKS();
		FMO_OPERATION();
	}
	/*	
	if(Type_In!=0||1||2||3)
	{
		Type_I = Type_In;
		Type_S = "DEF";
		FMO_GET_SIZE_OF_FILE();
		FMO_SET_CHUNKS();
		FMO_OPERATION();

	}
	*/
		
}	

void File_Mem_Operations::FMO_GET_SIZE_OF_FILE()
{
	int Counter;
	string buffer;
	do 
	{
		getline(*Price_File,buffer);    
		Counter++;
		
	}while(buffer!="");
	Price_File->seekg (0, Price_File->beg);
	Size = Counter;
}

void File_Mem_Operations::FMO_SET_CHUNKS()
{
	int Range=Size;
    int SIZE = (Period*100)-1;
    int RangeCount=0;
    int BUFFER=SIZE;
    double DIV = Range/BUFFER;
    int BR;
    if(Range%BUFFER!=0)
    {
		BR = round(DIV);
		BR = BR + 1;
	}
	else
	{
		BR = DIV;
	}   
    Range = BUFFER * BR;
    int Loops = Range/BUFFER;
    Chunks = Loops;
    Size_Of_Chunk = BUFFER;
}


void File_Mem_Operations::FMO_OPERATION()
{
	//Loop Chunks
		//extract Price
		//Put Price in Mem
		//Run Indicator Algo // SMA,EMA,DC .. run every indicator
		//Output to File
	//Until Chunks = N
	double ARRAY_PRICE[Size_Of_Chunk+1];
	double ARRAY_IND[Size_Of_Chunk+1];
	int RangeCount=0;
   
	do
    {	
		for(int i=0;i<(Size_Of_Chunk);i++) //Period = 0 , Buffer = 0
		{
		    getline(*Price_File,Buffer);
		    istringstream so(Buffer);
		    so>>Price;
		    ARRAY_PRICE[i]=Price;
		    ARRAY_IND[i] = 0;
		}
		IND.IND_SMA(ARRAY_PRICE,ARRAY_IND,Size_Of_Chunk,Period);
		for(int i=0;i<(Size_Of_Chunk);i++) //Period = 0 , Buffer = 0
		{
		    *Ind_File<<ARRAY_IND[i]<<endl;
		}
	}while(RangeCount!=Chunks);

	//Loop Indicator here
	//Output to file 

}



//xyz








