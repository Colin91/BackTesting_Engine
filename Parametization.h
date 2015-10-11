#ifndef PARAMETIZATION_H
#define PARAMETIZATION_H
#include "Strats.h"
using namespace std;
template <class T>

class Parametization
{
	public:
		Parametization(); //Object, Total No of Parameters, No of parameters to be parametized
		~Parametization();
		void PARAM_Loops(Strats,int,double[][5],int,int,int,double[],int,int,int,int,fstream*);
		
	private:
		Strats STR;
		double PARAM[][5];
		
};

#endif

