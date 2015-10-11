#include "Strats.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;
 
Strats::Strats()
{
    
}

Strats::~Strats()
{

}

int Strats::STR_Condition(double C1_In, double C2_In, int Flag_In)
{
	int Ret_Flag=0;
	if(Flag_In==0) //Check for equality
	{
		if(C1_In==C2_In)
		{
			Ret_Flag=1;
		}
	}
	if(Flag_In==1) //Check for C1>C2
	{
		if(C1_In>C2_In)
		{
			Ret_Flag=1;
		}
	}
	if(Flag_In==2) //Check for C1>C2
	{
		if(C1_In>=C2_In)
		{
			Ret_Flag=2;
		}
	}
	return Ret_Flag;
}

void Strats::TRINDIC(double ARRAY_In[][5],int Range_In,double* ARRAY_SMA,double* ARRAY_DC,double TRINDIC_ARR_In[]) // In the parameters list all Possible Variables to be parametized
{
	//TRINDIC_ARR[0] = Period;
    //TRINDIC_ARR[1] = DC_Change;
    //TRINDIC_ARR[2] = LookBackLambda;
    //TRINDIC_ARR[3] = TP;
    //TRINDIC_ARR[4] = SL;
    //TRINDIC_ARR[5] = Spread;
    //SMA and DC needs to be extracted from FILE.
        
    double BUY_Count=0;
    double SELL_Count=0;
    double POS;
    double NEG;
    double DIV=0;

	Indicators IND;
	Order ORD;

	double Long_Price,Short_Price;
	double Account;
	int Counter=1;
	int j=0;

	
	int Counter_Logic=0; // 1 = buy and 2 = sell
	ORD.set_ORD_Pip(0);
	
	
	for(int i=0;i<Range_In;i++) 
	{	
		if(ARRAY_SMA[0]!=0)
		{	
					//cout<<"SMA: "<<ARRAY_SMA[i]<<endl;
			if(ARRAY_SMA[i]>ARRAY_In[i][3]&&Counter_Logic==0)
			{
				ORD.ORD_Buy(ARRAY_In[i][3],TRINDIC_ARR_In[5]);
				ORD.ORD_TakeProfit(TRINDIC_ARR_In[3],1);
				ORD.ORD_StopLoss(TRINDIC_ARR_In[4],1);
				//cout<<Counter<<" -> "<<"Entry Long  : "<<ORD.get_ORD_Price()<<" SL : "<<ORD.get_ORD_StopLoss()<<" TP : "<<ORD.get_ORD_TakeProfit()<<endl;
				Counter++;
				Counter_Logic=1;
			}
			
			if(ARRAY_SMA[i]<ARRAY_In[i][3]&&Counter_Logic==0)
			{
				
				ORD.ORD_Sell(ARRAY_In[i][3],TRINDIC_ARR_In[5]);
				ORD.ORD_TakeProfit(TRINDIC_ARR_In[3],2);
				ORD.ORD_StopLoss(TRINDIC_ARR_In[4],2);
				//cout<<Counter<<" ->  "<<"Entry Short : "<<ORD.get_ORD_Price()<<" SL : "<<ORD.get_ORD_StopLoss()<<" TP : "<<ORD.get_ORD_TakeProfit()<<endl;
				Counter++;
				Counter_Logic=2;
			}
			
	
		}
		
		/*
			For each Price Processed Check TAKE_PROFIT and STOP_LOSS in case of a trigger.
			Check_ORD_TakeProfit function and others will trigger the ORD_Exit function internally in the ORDER Class
			ORD_Exit function will thus create the EXIT Price for which the P/L can be calculated
		*/
		if(Counter_Logic==1)
		{
			ORD.Check_ORD_TakeProfit(ARRAY_In[i][3],1,TRINDIC_ARR_In[3],Counter_Logic); //TakeProfit for Long
			ORD.Check_ORD_StopLoss(ARRAY_In[i][3],1,TRINDIC_ARR_In[4],Counter_Logic);     //StopLoss for Long
		}
		
		if(Counter_Logic==2)
		{
			ORD.Check_ORD_TakeProfit(ARRAY_In[i][3],2,TRINDIC_ARR_In[3],Counter_Logic); //TakeProfit for Short
			ORD.Check_ORD_StopLoss(ARRAY_In[i][3],2,TRINDIC_ARR_In[4],Counter_Logic);   //StopLoss for Short
		}
	
		
		//Curently Price exits on the next close
		
		if(ORD.get_ORD_Mode()==0&&Counter_Logic!=0)
		{			
			if(Counter_Logic==1)
			{
				//cout<<i<<" ->  "<<"Exit At : "<<ORD.get_ORD_Exit()<< " , Price : "<<ORD.get_ORD_Price()<<" P/L :"<<(ORD.get_ORD_Exit()-ORD.get_ORD_Price())/0.0001<<endl; 
				Account = Account + (ORD.get_ORD_Exit()-ORD.get_ORD_Price())/0.0001;
				//cout<<j<<"  ACCOUNT : +"<<Account<<endl;
				if(((ORD.get_ORD_Exit()-ORD.get_ORD_Price())/0.0001)>0)
				{
					POS++;
				}
				else
				{
					NEG++;
				}
				j++;
				BUY_Count++;
			 
			}
			if(Counter_Logic==2)
			{
				//cout<<i<<" ->  "<<"Exit At : "<<ORD.get_ORD_Exit()<<" P/L :"<<(ORD.get_ORD_Price()-ORD.get_ORD_Exit())/0.0001<<endl; 
				Account = Account + (ORD.get_ORD_Price()-ORD.get_ORD_Exit())/0.0001;
				//cout<<j<<"  ACCOUNT : -"<<Account<<endl;
				if(((ORD.get_ORD_Exit()-ORD.get_ORD_Price())/0.0001)>0)
				{
					POS++;
				}
				else
				{
					NEG++;
				}
				j++;
				SELL_Count++;
			}
			Counter_Logic=0;
		}
	
	}

	//cout<<" ["<<"ACCOUNT : "<<Account<<"] ";
	DIV = BUY_Count/SELL_Count;
	if(Account>500)
	{
		//cout<<" ["<<"ACCOUNT : "<<Account<<"] "<<"         BUY Trades : "<<BUY_Count<<"        , SELL Trades : "<<SELL_Count<<"        P:L :  "<<POS/NEG<<endl;

	}
	Account=0;

}




