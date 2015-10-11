#include "Indicators.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

Indicators::Indicators()
{

}

Indicators::~Indicators()
{

}

void Indicators::IND_SMA(double* ARRAY_In,double* ARRAY_IND_In,int RANGE_In,int PERIOD_In)
{
    double Price=0.0;
    double Price_Cumulative=0.0;
    int Counter=0;
    
    /*
    	File_Mem_Operations FMO(FP_IN);
    	do
    	{
    		Counter++;
    		
    		double* Array_Out = FMO_GET_FROM_FILE(FP_IN)
   		
    		////SMA op using Arrayout
    		delete Array_Out //since it will be allocated on the heap
    		ARRAY_Out = NULL //to avoid dangling pointers
    		
    		
    	}while(Counter!=FMO.getChunks())
     */    
    for(int a=0;a<=RANGE_In-PERIOD_In+1;a++) // a = 1 , a <= 9-3+1 = 7
    {
        for(int i=a;i<a+PERIOD_In;i++) 
        {
            Price_Cumulative=Price_Cumulative+ARRAY_In[i];
        }
        Price = (Price_Cumulative/PERIOD_In);
       	ARRAY_IND_In[a] = Price;
        Price_Cumulative=0;
    } 	
        
}

/*
//EMAtoday = α⋅xtoday + (1-α)EMAyesterday
void Indicators::IND_EMA(double ARRAY_In[][5],fstream* FP_In,double* ARRAY_EMA_In,int RANGE_In,int PERIOD_In,double *last)
{
	double Mult=0.0;
	double Price=0.0;
	double Prev_Price=0.0;
    double Price_Cumulative=0.0;
    int Counter=0;
  
	Mult = 2.0/(PERIOD_In+1);
	
    for(int a=0;a<=RANGE_In-PERIOD_In+1;a++)
    {
        for(int i=a;i<a+PERIOD_In;i++)
        {
            Price_Cumulative=Price_Cumulative+ARRAY_In[i][3];
        }
        Price = (Price_Cumulative/PERIOD_In);
        ARRAY_EMA_In[a] = Price; 
        Price_Cumulative=0;     
    }
     
    
    //ARRAY_EMA_In[0] = *last;
    ARRAY_EMA_In[0] = 0;
    cout<<0<<" , "<<ARRAY_EMA_In[0]<<endl;

    for(int i=1;i<=RANGE_In-3;i++)
    {
    	ARRAY_EMA_In[i] = ((ARRAY_In[i+3][3] - ARRAY_EMA_In[i-1])*Mult) + ARRAY_EMA_In[i-1];
    	cout<<i<<" , "<<ARRAY_EMA_In[i]<<endl;
    }
    //last=(double * )malloc(sizeof(double));
    //*last = ARRAY_EMA_In[(RANGE_In-PERIOD_In)]; //use of malloc to save last value in heap and does not get popped, this goes as the first value in the new calculation from the previous batch.
    //cout<<*last<<endl;
    cout<<"---"<<endl;
     
}

/*
    Sum 14 True Ranges to get TR14
	Smooth it: TR14 – (TR14/14) + Current TR
	For following calculations: Prior TR14 – (Prior TR14/14) + Current TR14
*/
/*
void Indicators::IND_ADX(double ARRAY_In[][5],double* ARRAY_ADX_In,int RANGE_In,int PERIOD_In)
{
	double* TRUE_RANGE = new double[RANGE_In];
	double* DireM_One_Pos = new double[RANGE_In];
	double* DireM_One_Neg = new double[RANGE_In];
	
	double* DireM_PERIOD_Pos = new double[RANGE_In];
	double* DireM_PERIOD_Neg = new double[RANGE_In];
	
	double* TRUE_RANGE_PERIOD = new double[RANGE_In];
	double* DireI_PERIOD_Pos = new double[RANGE_In];
	double* DireI_PERIOD_Neg = new double[RANGE_In];
	
	double* DireI_PERIOD_SUM = new double[RANGE_In];
	double* DireI_PERIOD_DIFF = new double[RANGE_In];
	double Counter=0.0;
	double* DX = new double[RANGE_In];
	
	double DM_PERIOD_POS;
	double DM_PERIOD_NEG;
	double TRUE_RANGEs;
		
	for(int i=1;i<RANGE_In;i++)
	{
		TRUE_RANGE[i] = ARRAY_In[i][1] - ARRAY_In[i][2]; //High-Close
		if(ARRAY_In[i][1] - ARRAY_In[i-1][1]>0)
		{
			DireM_One_Pos[i] = ARRAY_In[i][1] - ARRAY_In[i-1][1];//High-High	
		}
		if(ARRAY_In[i][1] - ARRAY_In[i-1][1]<0)
		{
			DireM_One_Neg[i] = Absolute(ARRAY_In[i][1] - ARRAY_In[i-1][1]);
		}
	}
	
	for(int i=1;i<RANGE_In;i++)
	{
		for(int s=PERIOD_In;s<i+PERIOD_In;s++)
		{
			TRUE_RANGEs = TRUE_RANGEs+TRUE_RANGE[i];
			DM_PERIOD_POS = DM_PERIOD_POS + DireM_One_Pos[s];
			DM_PERIOD_NEG = DM_PERIOD_NEG + DireM_One_Neg[s];
		}
		TRUE_RANGE_PERIOD[i] = TRUE_RANGEs;
		DireM_PERIOD_Pos[i] = DM_PERIOD_POS;
		DireM_PERIOD_Neg[i] = DM_PERIOD_NEG;
		
		DireI_PERIOD_Pos[i] =  (DM_PERIOD_POS/TRUE_RANGEs)*100;
		DireI_PERIOD_Neg[i] =  (DM_PERIOD_NEG/TRUE_RANGEs)*100;
		
		DireI_PERIOD_SUM[i] = DireI_PERIOD_Pos[i] + DireI_PERIOD_Neg[i]; 
		DireI_PERIOD_DIFF[i] = DireI_PERIOD_Pos[i] - DireI_PERIOD_Neg[i];
		
		DX[i] = DireI_PERIOD_SUM[i]/DireI_PERIOD_DIFF[i];
		
		ARRAY_ADX_In[i] = DX[i]/PERIOD_In;
		//cout<<ARRAY_ADX_In[i]<<endl;
			
		TRUE_RANGEs=0;
		DM_PERIOD_POS=0;
		DM_PERIOD_NEG=0;
	}
	
}

void Indicators::IND_RSI(double ARRAY_In[][5],double* ARRAY_RSI_In,int RANGE_In,int PERIOD_In)
{
	double ABS_CHANGE=0;
	double PREV_ABS_CHANGE=0; //ABS_CHANGE of the value to be popped.  for 3 period ->   yy [xx xx xx] , yy = PREV_ABS_CHANGE
	double AVE_GAIN=0;
	double AVE_LOSS=0;
	double *GAIN = new double[RANGE_In];
	double *LOSS = new double[RANGE_In];
	double CURR_CHANGE=0;
	double RS=0;
	
	
	for(int s=1;s<RANGE_In;s++)
	{
		CURR_CHANGE = ARRAY_In[s][3]-ARRAY_In[s-1][3];
		if(CURR_CHANGE>0)
		{
			GAIN[s] = CURR_CHANGE;
		}
		if(CURR_CHANGE<0)
		{
			LOSS[s] = Absolute(CURR_CHANGE);
		}	
		if(CURR_CHANGE==0)
		{
			GAIN[s] = 0;
			LOSS[s] = 0;
		}	
	}
	
	for(int p=1;p<RANGE_In;p++)
	{
		for(int i=p;i<p+PERIOD_In;i++)
		{
			AVE_GAIN = AVE_GAIN + GAIN[i];
			AVE_LOSS = AVE_LOSS + LOSS[i];
		}
		AVE_GAIN = AVE_GAIN/PERIOD_In;
		AVE_LOSS = AVE_LOSS/PERIOD_In;	
		RS = AVE_GAIN/AVE_LOSS;
		ARRAY_RSI_In[p] = 100 - (100/(1+RS));
		if(ARRAY_RSI_In[p]==NAN)
		{
			ARRAY_RSI_In[p]=50;
		}
		AVE_GAIN=0;
		AVE_LOSS=0;
		RS=0;
	}	
}

void Indicators::IND_DC(double ARRAY_In[][5],fstream* FP_In,int RANGE_In,int Mode_In,int LookBackLambda_In,double DC_Change) 
{

	if(LookBackLambda_In==0)
	{
		LookBackLambda_In=1;
	}
	for(int i=LookBackLambda_In;i<RANGE_In;i++)
	{
		if(Mode_In==0) //HIGH[i] - LOW[i-1]
		{
			*FP_In<<((ARRAY_In[i][1] - ARRAY_In[i-LookBackLambda_In][2])/ARRAY_In[i-LookBackLambda_In][2])*100;			
		}
		
		if(Mode_In==1) //CLOSE[i]-CLOSE[i-1]
		{
			*FP_In<<((ARRAY_In[i][3] - ARRAY_In[i-LookBackLambda_In][3])/ARRAY_In[i-LookBackLambda_In][3])*100;
		}
		
		if(Mode_In==2) //HIGH[i] - HIGH[i-1]
		{
			*FP_In<<((ARRAY_In[i][1] - ARRAY_In[i-LookBackLambda_In][1])/ARRAY_In[i-LookBackLambda_In][1])*100;
		}
		
		if(Mode_In==3) //LOW[i] - LOW[i-1]
		{
			*FP_In<<((ARRAY_In[i][2] - ARRAY_In[i-LookBackLambda_In][2])/ARRAY_In[i-LookBackLambda_In][2])*100;
		}
			
	}

	
}

*/
double Indicators::Absolute(double Input)
{
	if(Input<0.0)
	{
		Input = (Input/(-1));
	}
	return Input;
}







/*
    
    //////////////////////BUFFER//////////////////////////////////
    SMA
    do
    {
		for(int s=Counter;s<PERIOD_In-1;s++)
		{
			Price_Cumulative = Price_Cumulative + Buffer_In[s][3];
		}

		for(int i=0;i<=Counter;i++)
		{
			Price_Cumulative = Price_Cumulative + ARRAY_In[i][3];
		}
		Price = (Price_Cumulative/PERIOD_In);
		ARRAY_SMA_In[Counter] = Price;
		Counter++;
		//cout<<Price<<endl;
		Price_Cumulative=0;
		
	}while(Counter!=PERIOD_In-1);
	
	/////////////////////////////////////////////////////
	
		//////////////////////BUFFER//////////////////////////////////
    /*
    EMA
    do
    {
		for(int s=Counter;s<PERIOD_In-1;s++)
		{
			Price_Cumulative = Price_Cumulative + Buffer_In[s][3];
		}

		for(int i=0;i<=Counter;i++)
		{
			Price_Cumulative = Price_Cumulative + ARRAY_In[i][3];

		}
		Price = (Price_Cumulative/PERIOD_In);
		ARRAY_EMA_In[Counter] = Price;
		Counter++;

		Price_Cumulative=0;
		Mult = 2.0/(PERIOD_In+1);   
		ARRAY_EMA_In[0] = 0.0;
		ARRAY_EMA_In[1] = Price;
		

		for(int i=2;i<RANGE_In;i++)
		{
			ARRAY_EMA_In[i] = (ARRAY_In[i][3] - ARRAY_EMA_In[i-1])*Mult + ARRAY_EMA_In[i-1];
			cout<<" i ; "<<ARRAY_EMA_In[i]<<endl;
		}
		

		
	}while(Counter!=PERIOD_In-1);
	*/

























