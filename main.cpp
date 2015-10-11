#include <fstream>
#include <string.h>
#include <sstream>
#include <istream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <unistd.h>
#include "Indicators.h"
#include "Account.h"
#include "Account.cpp"
#include "Parametization.cpp"
#include "Order.h"
#include "Strats.h"
#include "OrderList.h"
#include "DataSet.h"
#include "File_Mem_Operations.h"
#include <ctime>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

/*

The best programs are written so that computing machines can perform them quickly and so that human beings can understand them clearly. A programmer is ideally an essayist who works with traditional aesthetic and literary forms as
well as mathematical concepts, to communicate the way that an algorithm works and to convince a reader that the results will be correct. ― Donald E. Knuth
*/

//DataSet Range 01/01/2013 - 31/05/2015 - Imported from Dukascopy.com

struct Price_Combo
{
	double OPEN;
	double HIGH;
	double LOW;
	double CLOSE;
}Struct_Price;


int main(int argc,char** argv)
{
	//Calculates time : START
	clock_t start;
	double duration;
	start = clock();
	//Calculates time : END
	
	//Declarations : START
	int Counter=0;
	int BUY_MODE=0;
    Indicators IND;
    Order ORD;
    Order* ARRAY_ORDERS = new Order[100000];
    OrderList ORDL(ARRAY_ORDERS);
    Order ORD1;
    Parametization<Strats> PRM;	
	double TP = 120;
	double SL = 25;	
	double Spread=0;
    double Price,TakeProfit,StopLoss,Exit;
    fstream FP_OPEN;
    fstream FP_HIGH;
    fstream FP_LOW;
    fstream FP_CLOSE;
    fstream FP_IND_SMA;
    fstream FP_IND_EMA;
    fstream FP_IND_DC;
    fstream FP_PARAM;
    fstream FP_DS;   
    
    //Declarations : END
    
     //Since outputting to file for Indicators overwrites the previous block, A counter must keep track of the current 
    // This section adjusts Range to become a Multiple of Period
    
    
    //CHUNKS ALGO
    //Buffer Calculate : START 
    int Range=100;
    int Period=3;
    int SIZE = (Period*3)-1;
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
    //Buffer Calculate : END
    
 
	
	//Declarations for FILES : START
	string buffer,buffer1,buffer2,buffer3;
    //FP_OPEN.open("EURUSD1_MIN_OPEN.txt",ios::in);
    //FP_HIGH.open("EURUSD1_MIN_HIGH.txt",ios::in);
    //FP_LOW.open("EURUSD1_MIN_LOW.txt",ios::in);
    FP_CLOSE.open("EURUSD1_MIN_CLOSE.txt",ios::in);
    
    FP_IND_SMA.open("Indicator_SMA.txt",ios::out);
    //FP_IND_EMA.open("Indicator_EMA.txt",ios::out);
    //FP_IND_DC.open("Indicator_DC.txt",ios::out);
    //FP_PARAM.open("PARAM_STRATS.txt",ios::out);
   
    double ARRAY_PRICE[SIZE][5]; //OHLC
    double ARRAY_BUFFER[Period-1][5];
    double ARRAY_SMA[SIZE];
    double ARRAY_DC[SIZE];
    double* ARRAY_EMA = new double[SIZE];   
    double* last;

    double CONV_To_DOUBLE=0;
    double OPEN=0,HIGH=0,LOW=0,CLOSE=0;
    double DC_Change=0.02;
    int LookBackLambda = 2;
    int SWITCH=0;

    Strats STR;
    double TRINDIC_ARR[10];
    TRINDIC_ARR[0] = Period;
    TRINDIC_ARR[1] = DC_Change;
    TRINDIC_ARR[2] = LookBackLambda;
    TRINDIC_ARR[3] = TP;
    TRINDIC_ARR[4] = SL;
    TRINDIC_ARR[5] = Spread;
    
    int ProxySize=SIZE;
    int OuterCount=0;
    int InnerCount=0;
    
   	double Pricess;
     
    //getline(FP_CLOSE,buffer);
    //istringstream so(buffer);
    //so>>Pricess;
    //cout<<"PRice: "<<Pricess<<endl;

    File_Mem_Operations FMO(&FP_CLOSE,&FP_IND_SMA,0,0,IND,Period); 
    
    //Declarations for FILES : END
         
  

	//FMO.FMO_GET_SIZE_OF_FILE();
	//FMO.FMO_SET_CHUNKS();

	DataSet DS(&FP_DS);
    char name[256];
    char path[256];
    DS.DS_setCurrency(name,path,argv);
    DS.DS_Set_1_Min(ARRAY_PRICE);
    DS.DS_Set_5_Min(ARRAY_PRICE);
  
    FP_OPEN.close();
    FP_HIGH.close();
    FP_LOW.close();
    FP_CLOSE.close();
    FP_IND_SMA.close();
    FP_IND_EMA.close();
	FP_PARAM.close();
    FP_DS.close();
    
    /*
	TRINDIC_ARR[0] = Period;
    TRINDIC_ARR[1] = DC_Change;
    TRINDIC_ARR[2] = LookBackLambda;
    TRINDIC_ARR[3] = TP;
    TRINDIC_ARR[4] = SL;

    TRINDIC_ARR[5] = Spread;
	*/
	//Strats STR_In,int Range_In,double ARRAY_In[][4],int Start_In, int End_In, int Multiples_In, double ParameterArray[], int PARAM_In
	int Counters=0;	
	cout<<" COUNT : "<<Counters++<<endl;
	
	//PRM.PARAM_Loops(STR,Range,ARRAY_PRICE,14,100,1,TRINDIC_ARR,0,0,0,0,&FP_IND);
	//PRM.PARAM_Loops(STR,Range,ARRAY_PRICE,20,200,5,TRINDIC_ARR,0,3,4,0,&FP_IND);
	//PRM.PARAM_Loops(STR,Range,ARRAY_PRICE,20,200,10,TRINDIC_ARR,4,3,4,1,&FP_IND);
    
 	//delete ARRAY_ORDERS;
    
    //Program Time Duration : START
    duration  = (clock()-start) / (double) CLOCKS_PER_SEC;
    cout<<"DURATION : "<<duration<<endl;
    cout<<argv[0]<<endl;
    //Program Time Duration : END
    
   
    return 0;
}


/*
  do
    {	
		for(int i=Period-1;i<=(SIZE);i++) //Period = 0 , Buffer = 0
		{
		    getline(FP_OPEN,buffer);
		    getline(FP_HIGH,buffer1);
		    getline(FP_LOW,buffer2);
		    getline(FP_CLOSE,buffer3);
		    
		    istringstream so(buffer);
		    so>>OPEN;
		    istringstream sh(buffer1);
		    sh>>HIGH;
		    istringstream sl(buffer2);
		    sl>>LOW;
		    istringstream sc(buffer3);
		    sc>>CLOSE;
     
		    ARRAY_PRICE[i][0]=OPEN;
		    ARRAY_PRICE[i][1]=HIGH;
		    ARRAY_PRICE[i][2]=LOW;
		    ARRAY_PRICE[i][3]=CLOSE;
	
		    OuterCount++;	//7    
		    //cout<<i<<" ----------------------------------____>>>> "<<ARRAY_PRICE[i][0]<<endl;   
		    //cout<<i<<" ----------------------------------____>>>> "<<ARRAY_PRICE[i][1]<<endl; 
		    //cout<<i<<" ----------------------------------____>>>> "<<ARRAY_PRICE[i][2]<<endl; 
		    //cout<<i<<" ----------------------------------____>>>> "<<ARRAY_PRICE[i][3]<<endl;   
		}
		//IND.IND_SMA(ARRAY_PRICE,&FP_IND_SMA,SIZE,TRINDIC_ARR[0]);
		//IND.IND_DC(ARRAY_PRICE,&FP_IND_DC,TRINDIC_ARR[0],0,TRINDIC_ARR[2],TRINDIC_ARR[1]);
		//IND.IND_EMA(ARRAY_PRICE,&FP_IND_EMA,ARRAY_EMA,SIZE,TRINDIC_ARR[0],last);
		//STR.TRINDIC(ARRAY_PRICE,Range,&FP_IND_SMA,&FP_IND_DC,TRINDIC_ARR);
		
		for(int s=Period;s>0;s--)
		{
			ARRAY_PRICE[InnerCount][0] = ARRAY_PRICE[(OuterCount+Period)-s][0];
		    ARRAY_PRICE[InnerCount][1] = ARRAY_PRICE[(OuterCount+Period)-s][1];
		   	ARRAY_PRICE[InnerCount][2] = ARRAY_PRICE[(OuterCount+Period)-s][2];
		    ARRAY_PRICE[InnerCount][3] = ARRAY_PRICE[(OuterCount+Period)-s][3];

		    InnerCount++;
		}
		InnerCount=0;
		OuterCount=0;
		RangeCount++;
		cout<<"------------"<<RangeCount<<endl;
		
	}while(RangeCount!=Loops);
*/	
	

















