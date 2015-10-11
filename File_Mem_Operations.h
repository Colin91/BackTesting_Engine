#ifndef FILE_MEM_OPERATIONS_H
#define FILE_MEM_OPERATIONS_H
#include <string>
#include "Indicators.h"
#include "Strats.h"
using namespace std;


class File_Mem_Operations //aka MaxData Algo
{
	public:
		File_Mem_Operations(fstream*,fstream*,int,int,Indicators,int); //File,type,Indicator In List(0-SMA,1-EMA),Period **
		~File_Mem_Operations();	
		void FMO_SET_TYPE(int); //set to private
		void FMO_SET_CHUNKS();  //set to private
		void FMO_SET_BUFFER();  //set to private
		void FMO_GET_SIZE_OF_FILE();
		void FMO_OPERATION();
	private:
		int Key;
		int Period;
		int Chunks;
		int Size;
		int Size_Of_Chunk;
		string FileName;
		
		string Buffer;
		double Price;
		
		string Type_S;
		int Type_I;
		fstream *Price_File;
		fstream *Ind_File;
		fstream *ReturnFileAddress;	
		Indicators IND;
		Strats STR;
		
		
		
};

#endif

/* ** File Pointer -> type 0 - Default	   
						   1 - Indicators -> 0 - SMA
						   					 1 - EMA -> Period
						   
						   2 - Strategy   -> 0 - Trindic01
										  -> 1 - Trindic02 -> 			

*/


