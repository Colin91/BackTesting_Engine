#include "Order.h"
#include <string.h>
#include <iostream>
#include <math.h>
#include <stdio.h>  
#include <stdlib.h> 
using namespace std;

/*Errors
ERR_ORD_01 = No Buy and Sell Orders
ERR_ORD_02 = Invalid Take Profit
ERR_ORD_03 = Invalid Stop Loss
ERR_ORD_04 = Invalid Spread
ERR_ORD_05 = Invalid Price
ERR_ORD_06 = Invalid PIPS
*/

Order::Order() 
{
	Mode=0;
}


Order::~Order()
{
	
}

//This is straightfoward, for Major currencies pip value is 0.0001 and for YEN it is 0.01

void Order::set_ORD_Pip(int CURRENCY_ID_IN) // Yen = 0.01 , Others = 0.0001
{
	if(CURRENCY_ID_IN==0||CURRENCY_ID_IN==1)
	{	
		if(CURRENCY_ID_IN==0)
		{
			Pips=1*0.0001;
			PipMode=0;
		}
		if(CURRENCY_ID_IN==1)
		{
			Pips=1*0.01;
			PipMode=1;
		}
	}
	else
	{
		cout<<"ERR_ORD_07 - Invalid Pip Mode"<<endl;
	}

}

/*
	Input Price of Entry
	Deduct Spread from Price
	Set Price
*/
void Order::ORD_Buy(double Price_In,double Spread_In) //0 - Cash, 1 - Buy, 2 - Sell
{
	double ReturnPrice=0.0;
	//cout<<Price_In<<endl;
	if(Spread_In<0)
	{
		cout<<"ERR_ORD_04 - Invalid Spread"<<endl;
		
	}
	else if(Price_In<0)
		 {
			 cout<<"ERR_ORD_05 - Invalid Price"<<endl;
		 }
		 else
		 {
		 	Mode=1;
			Spread=Spread_In*Pips;
			Price=Price_In-Spread;
		 }
	BUY_Counter++; //Keeps Track of the number of Buy Trades
}
/*
	Input Price of Entry
	Deduct Spread from Price
	Set Price
*/
void Order::ORD_Sell(double Price_In,double Spread_In)
{
	double ReturnPrice=0.0;
	if(Spread_In<0)
	{
		cout<<"ERR_ORD_04 - Invalid Spread"<<endl;
		
	}
	else if(Price_In<0)
		 {
			 cout<<"ERR_ORD_05 - Invalid Price"<<endl;
		 }
		 else
		 {
		 	Mode=2;
			Spread=Spread_In*Pips;
			Price=Price_In+Spread;
		 }
	SELL_Counter++; //Keeps Track of the number of Sell Trades
}

/*
	This Order is set at the option of the trader. 1 order at a time can be set.
	However Multiple Orders can be created by creating Multiple Objects.
*/

void Order::ORD_TakeProfit(double Pips_In,int Mode_In)
{
	double Price_Out=0.0;
	TAKEPROFIT_PIPS = Pips_In;
		if(Price>0)
		{
			if(Pips_In<0)
			{
				cout<<"ERR_ORD_02 - Invalid Take Profit"<<endl;
			}	
			else
			{
				if(Mode==1) //TakeProfit
				{
					Pips_In=Pips_In*Pips;
			 		Price_Out = Price + Pips_In;
			 		TakeProfit = Price_Out;
				}
	
				if(Mode==2) //StopLoss
				{
					Pips_In=Pips_In*Pips;
					Price_Out = Price - Pips_In;
					TakeProfit = Price_Out;
				}
			}
		}
		else
		{
			cout<<"ERR_ORD_05 - Invalid Price"<<endl;
		}
}

/*
	This Order is set at the option of the trader. 1 order at a time can be set.
	However Multiple Orders can be created by creating Multiple Objects.
*/
void Order::ORD_StopLoss(double Pips_In,int Mode_In)
{
	double Price_Out=0.0;
	STOPLOSS_PIPS = Pips_In;
		if(Price>0)
		{
			if(Pips_In<0)
			{
				cout<<"ERR_ORD_03 - Invalid Stop Loss"<<endl;
			}	
			else
			{
				if(Mode==1) //TakeProfit
				{
					Pips_In=Pips_In*Pips;
			 		Price_Out = Price - Pips_In;
			 		StopLoss = Price_Out;
				}
	
				if(Mode==2) //StopLoss
				{
					Pips_In=Pips_In*Pips;
					Price_Out = Price + Pips_In;
					StopLoss = Price_Out;
				}
			}
		}
		else
		{
			cout<<"ERR_ORD_05 - Invalid Price"<<endl;
		}
}

/*
	This is the final function for the trade.
	Exit Price is defined
*/

void Order::ORD_Exit(double Price_In,int Mode_In,int OrderType_In)
{
	double Price_Out;
	if(Mode_In==0)
	{
		cout<<"No Order Placed"<<endl;
	}
	else
	{
		if(Mode_In==1&&OrderType_In==1) //Takeprofit for Long
		{
			Exit = Price_In;
			Mode=0;
		}
	
		if(Mode_In==1&&OrderType_In==2) //StopLoss for Long
		{	
			Exit = Price_In;	
			Mode=0;
		}
		if(Mode_In==2&&OrderType_In==1) //Takeprofit for Short
		{
			Exit = Price_In;
			Mode=0;
		}
	
		if(Mode_In==2&&OrderType_In==2) //StopLoss for Short
		{	
			Exit = Price_In;
			Mode=0;
		}
	}
}

void Order::Check_ORD_TakeProfit(double Price_In,int Mode_In,double TakeProfit_In,int BUY_SELL_Mode)
{

	TakeProfit_In=TakeProfit_In*Pips;
	if(Mode_In==1&&((Price_In-Price)>=TakeProfit_In)&&Price_In>Price&&BUY_SELL_Mode!=0) // Long TakePofit
	{
		ORD_Exit(Price+TakeProfit_In,1,1);
		Mode=0;
	}	
	if(Mode_In==2&&(Price-Price_In)>=TakeProfit_In&&Price_In<Price)   // Short TakeProfit
	{
		ORD_Exit(Price-TakeProfit_In,1,1);
		Mode=0;
	}
}

void Order::Check_ORD_StopLoss(double Price_In, int Mode_In,double StopLoss_In,int BUY_SELL_Mode)
{
	StopLoss_In=StopLoss_In*Pips;
	if(Mode_In==1&&((Price-Price_In)>=StopLoss_In)&&Price_In<Price&&BUY_SELL_Mode!=0) // Long StopLoss
	{
		ORD_Exit(Price-StopLoss_In,1,2);
		Mode=0;
	}	
	if(Mode_In==2&&(Price_In-Price)>=StopLoss_In&&Price<Price_In)  // Short StopLoss
	{
		ORD_Exit(Price+StopLoss_In,1,2);
		Mode=0;
	}
	
}

double Order::get_ORD_Price()
{
	return Price;
}

int Order::get_ORD_Mode()
{
	return Mode;
}

double Order::get_ORD_Spread()
{
	return Spread;
}

double Order::get_ORD_TakeProfit()
{
	return TakeProfit;
}

double Order::get_ORD_StopLoss()
{
	return StopLoss;
}

double Order::get_ORD_Exit()
{
	return Exit;
}

int Order::get_ORD_NumberofBUYS()
{
	return BUY_Counter;
}

int Order::get_ORD_NumberofSELLS()
{
	return SELL_Counter;
}

int Order::get_ORD_TakeProfit_PIPS()
{
	return TAKEPROFIT_PIPS;
}

int Order::get_ORD_StopLoss_PIPS()
{
	return STOPLOSS_PIPS;
}



