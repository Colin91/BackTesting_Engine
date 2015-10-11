#include "Parametization.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
template <class T>
/*

The common procedure in C++ is to put the class definition in a C++ header file and the implementation in a C++ source file. Then, the source file is made part of the project, meaning it is compiled separately. But when we implement this procedure for template classes, some compilation and linking problems will arise.

Reason

In this case, the compiler doesn't know about the object type. So it will not compile.

Solution

To compile this class without any errors, you need to put the template specific declaration in a .cpp file, as shown below:

*/

Parametization<T>::Parametization()
{	
	
}	

template<class T>
Parametization<T>::~Parametization()
{

}

template <class T>
void Parametization<T>::PARAM_Loops(Strats STR_In,int Range_In,double ARRAY_In[][5],int Start_In, int End_In, int Multiples_In, double ParameterArray[], int PARAM_In, int START_PARAM_In, int END_PARAM_In,int Mode_In,fstream *FP_In) //Mode = 0 : Parametize simultaneously , 1 : Parametize sequentially
{
	int Counter=-1;
	int s;
	int Range = START_PARAM_In - END_PARAM_In;
	
	double ARRAY_SMA[100];
	double ARRAY_DC[100];
	if(Range==0)
	{	
		//cout<<"First"<<endl;
		for(int i=Start_In;i<End_In;i++)
		{
			//cout<<i<<" : ";
			ParameterArray[PARAM_In] = i;
			STR_In.TRINDIC(ARRAY_In,Range_In,ARRAY_SMA,ARRAY_DC,ParameterArray);
			i = (i + Multiples_In) - 1;
		}
	}
	else if(Mode_In==0&&Range!=0)
		 {
		 		//cout<<"Second"<<endl;
				for(int i=Start_In;i<End_In;i++)
				{
					for(int s=START_PARAM_In;s<=END_PARAM_In;)
					{
						ParameterArray[s] = i;
						s++;
					}							
					STR_In.TRINDIC(ARRAY_In,Range_In,ARRAY_SMA,ARRAY_DC,ParameterArray);
					i = (i + Multiples_In) - 1;
    			}
		}
		else if(Mode_In==1)
			 {
			 	//cout<<"Third"<<endl;
			 	s=START_PARAM_In;
			 	do
				{
					for(int i=Start_In;i<=End_In;i++)
					{
						//cout<<i<<" : ";
						ParameterArray[s] = i;							
						STR_In.TRINDIC(ARRAY_In,Range_In,ARRAY_SMA,ARRAY_DC,ParameterArray);
						i = (i + Multiples_In) - 1;
					}
					s++;
					Counter++;
					cout<<Counter<<endl;
				}while(Counter==Range+1);
			 }
}



