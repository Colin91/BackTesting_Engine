#ifndef DATASET_H
#define DATASET_H
#include <fstream>
using namespace std;


/*
	Import Indicator List // SMA,EMA..
	Import Price List // EURUSD 1m,5m,30m or GBPUSD 1m,5m,30m
*/
class DataSet
{

	public:
		DataSet(fstream*);
		void DS_setCurrency(char*,char*,char**); //MakeFolder
		//Each DataSet will contain : Name of File.txt, double[][5] -> Date,O,H,L,C
		void DS_Set_1_Min(double[][5]); 
		void DS_Set_5_Min(double[][5]);
		void DS_Set_15_Min(double[][5]);
		void DS_Set_30_Min(double[][5]);
		void DS_Set_60_Min(double[][5]);
		void DS_Set_240_Min(double[][5]);
		fstream& DS_Get_1_Min();
		fstream& DS_Get_5_Min();
		fstream& DS_Get_15_Min();	
		fstream& DS_Get_30_Min();
		fstream& DS_Get_60_Min();	
		fstream& DS_Get_240_Min();
		const char DS_get_Folder_Path();
		const char DS_get_Folder_Name();
		
		
	private:
		char *DS_CurrName; //const char* is used so that the data cannot be changed, char *const DS_Currname = &Address will hold the address constant
		char *DS_Folder_Path;
		char *DS_CurrMinute;
		char *DS_CurrMinute_Folder;
		fstream *File_Pointer;
		const char* Min_1;
		const char* Min_5;
		const char* Min_15;
		const char* Min_30;
		const char* Min_60;
		const char* Min_240;
		int File_Flag;

};


#endif
