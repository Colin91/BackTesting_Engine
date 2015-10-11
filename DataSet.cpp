#include "DataSet.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

DataSet::DataSet(fstream *FP_In)
{
	File_Pointer = FP_In;
}

void DataSet::DS_setCurrency(char* CurrencyName_In,char* the_path,char** argv)
{
	int Size=256;
    getcwd(the_path, Size);
    strcat(the_path, argv[0]);
	
	//This loop is used to filter out the name of the program and leave only the directory of the folder where the program lies.
	//For example C::/Programming/TradingEngine/./Program   -- the loop will remove ./Program and leaves the remaining, thus allowing the Folder containing the currencies to be created.
	for(int i=Size;i>0;i--)
	{
		if(the_path[i]!='/'&&the_path[i-1]!='.')
		{
			the_path[i-1]=0;
		}
		else
		{
			the_path[i] = 0;
			the_path[i-1] = '/';
			i=0;
		}
	}

	cout<<"Enter Folder name : "<<endl;
	cin>>CurrencyName_In;
	DS_CurrName = CurrencyName_In;
	DS_Folder_Path = strcat(the_path,DS_CurrName); //Append Folder name to path.
	DS_CurrMinute_Folder = DS_Folder_Path;
	mkdir(the_path,S_IRWXU | S_IRWXG | S_IRWXO);
	
}

void DataSet::DS_Set_1_Min(double DataSet_In[][5])
{
	int Size=250;
	int length=0;
	length = strlen(DS_Folder_Path);
	const char *File_Name;
	string str(DS_Folder_Path);
	string File_NameS="/1_Min.txt";
	string Combined = str + File_NameS;
	File_Name = Combined.c_str();
	Min_1 = File_Name;
	File_Pointer->open(File_Name,ios::out);
	File_Pointer->close();
	
}


void DataSet::DS_Set_5_Min(double DataSet_In[][5])
{
	int Size=250;
	int length=0;
	length = strlen(DS_Folder_Path);
	const char *File_Name;
	string str(DS_Folder_Path);
	string File_NameS="/5_Min.txt";
	string Combined = str + File_NameS;
	File_Name = Combined.c_str();
	Min_1 = File_Name;
	File_Pointer->open(File_Name,ios::out);
	File_Pointer->close();
	

}

void DataSet::DS_Set_15_Min(double DataSet_In[][5])
{
	int Size=250;
	int length=0;
	length = strlen(DS_Folder_Path);
	const char *File_Name;
	string str(DS_Folder_Path);
	string File_NameS="/15_Min.txt";
	string Combined = str + File_NameS;
	File_Name = Combined.c_str();
	Min_1 = File_Name;
	File_Pointer->open(File_Name,ios::out);
	File_Pointer->close();
}

void DataSet::DS_Set_30_Min(double DataSet_In[][5])
{
	int Size=250;
	int length=0;
	length = strlen(DS_Folder_Path);
	const char *File_Name;
	string str(DS_Folder_Path);
	string File_NameS="/30_Min.txt";
	string Combined = str + File_NameS;
	File_Name = Combined.c_str();
	Min_1 = File_Name;
	File_Pointer->open(File_Name,ios::out);
	File_Pointer->close();

}

void DataSet::DS_Set_60_Min(double DataSet_In[][5])
{
	int Size=250;
	int length=0;
	length = strlen(DS_Folder_Path);
	const char *File_Name;
	string str(DS_Folder_Path);
	string File_NameS="/60_Min.txt";
	string Combined = str + File_NameS;
	File_Name = Combined.c_str();
	Min_1 = File_Name;
	File_Pointer->open(File_Name,ios::out);
	File_Pointer->close();

}

void DataSet::DS_Set_240_Min(double DataSet_In[][5])
{
	int Size=250;
	int length=0;
	length = strlen(DS_Folder_Path);
	const char *File_Name;
	string str(DS_Folder_Path);
	string File_NameS="/240_Min.txt";
	string Combined = str + File_NameS;
	File_Name = Combined.c_str();
	Min_1 = File_Name;
	File_Pointer->open(File_Name,ios::out);
	File_Pointer->close();

}

fstream& DataSet::DS_Get_1_Min()
{
	
	if(File_Flag==0)
	{
		File_Pointer->open(Min_1,ios::in);
	}
	else
	{
		File_Pointer->close();
		File_Pointer->open(Min_1,ios::in);
	}	
	File_Flag=1; //Since File_Pointer can be used one at at a time, IF one is open its need to be closed in order to open the other.
	return *File_Pointer;
}

fstream& DataSet::DS_Get_5_Min()
{
	if(File_Flag==0)
	{
		File_Pointer->open(Min_5,ios::in);
	}
	else
	{
		File_Pointer->close();
		File_Pointer->open(Min_5,ios::in);
	}
	File_Flag=1;
	return *File_Pointer;
}

fstream& DataSet::DS_Get_15_Min()
{
	if(File_Flag==0)
	{
		File_Pointer->open(Min_15,ios::in);
	}
	else
	{
		File_Pointer->close();
		File_Pointer->open(Min_15,ios::in);
	}
	File_Flag=1;
	return *File_Pointer;
}

fstream& DataSet::DS_Get_30_Min()
{
	if(File_Flag==0)
	{
		File_Pointer->open(Min_30,ios::in);
	}
	else
	{
		File_Pointer->close();
		File_Pointer->open(Min_30,ios::in);
	}
	File_Flag=1;
	return *File_Pointer;
}

fstream& DataSet::DS_Get_60_Min()
{
	if(File_Flag==0)
	{
		File_Pointer->open(Min_60,ios::in);
	}
	else
	{
		File_Pointer->close();
		File_Pointer->open(Min_60,ios::in);
	}
	File_Flag=1;
	return *File_Pointer;
}

fstream& DataSet::DS_Get_240_Min()
{
	if(File_Flag==0)
	{
		File_Pointer->open(Min_240,ios::in);
	}
	else
	{
		File_Pointer->close();
		File_Pointer->open(Min_240,ios::in);
	}
	File_Flag=1;
	return *File_Pointer;
}

const char DataSet::DS_get_Folder_Path()
{
	return *DS_Folder_Path;
}

const char DataSet::DS_get_Folder_Name()
{
	return *DS_CurrName;
}






















