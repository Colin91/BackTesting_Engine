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


double Order::ORD_Buy(double Price_In,double Spread_In,int Counter_In) //0 - Cash, 1 - Buy, 2 - Sell
{
	double ReturnPrice=0.0;
	//cout<<Counter_In<<endl;
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
		 	//cout<<"Mode "<<Mode<<endl;
			Spread=Spread_In*0.0001;
			Price=Price_In-Spread;
			ReturnPrice = Price;	
		 }
	return ReturnPrice;
				
}

double Order::ORD_Sell(double Price_In,double Spread_In)
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
		 	//cout<<"Mode "<<Mode<<endl;
			Spread=Spread_In*Pips;
			Price=Price_In+Spread;
			ReturnPrice = Price;		 
		 }
	return ReturnPrice; //Inclusive of Spread

}

double Order::ORD_TakeProfit(double Pips_In,int Mode_In)
{
	double Price_Out=0.0;

		if(Price>0)
		{
			if(Pips_In<0)
			{
				cout<<"ERR_ORD_02 - Invalid Take Profit"<<endl;
			}	
			else
			{
				if(Mode==1)
				{
					Pips_In=Pips_In*Pips;
			 		Price_Out = Price + Pips_In;
			 		TakeProfit = Price_Out;
				}
	
				if(Mode==2)
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

	return TakeProfit;
}

double Order::ORD_StopLoss(double Pips_In,int Mode_In)
{
	double Price_Out=0.0;
		if(Price>0)
		{
			if(Pips_In<0)
			{
				cout<<"ERR_ORD_03 - Invalid Stop Loss"<<endl;
			}	
			else
			{
				if(Mode==1)
				{
					Pips_In=Pips_In*Pips;
			 		Price_Out = Price - Pips_In;
			 		StopLoss = Price_Out;
				}
	
				if(Mode==2)
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

	return StopLoss;
}

void Order::ORD_Exit(double Price_In,int Mode_In,int OrderType_In)
{
	double Price_Out;
	if(Mode_In==0)
	{
		cout<<"No Order Placed"<<endl;
	}
	if(Mode_In==1&&OrderType_In==1) //Takeprofit for Long
	{
		Price_Out = Price_In - Price;
		Exit = Price_Out;
		Mode=0;
		//cout<<"Exit Price : "<<Price_In<<" , "<<Exit<<endl;
		//ACC.set_Profit(Exit/Pips);
		
	}
	
	if(Mode_In==1&&OrderType_In==2) //StopLoss for Long
	{	
		Price_Out = Price - Price_In;
		Exit = Price_Out;
		Mode=0;
		//cout<<"Exit Price : "<<Price_In<<" , "<<Exit<<endl;
		//ACC.set_Loss(Exit/Pips);
	}
	if(Mode_In==2&&OrderType_In==1) //Takeprofit for Short
	{
		Price_Out = Price - Price_In;
		Exit = Price_Out;
		Mode=0;
		//cout<<"Exit Price : "<<Price_In<<" , "<<Exit<<endl;
		//ACC.set_Profit(Exit/Pips);
	}
	
	if(Mode_In==2&&OrderType_In==2) //StopLoss for Short
	{	
		Price_Out = Price_In - Price;
		Exit = Price_Out;
		Mode=0;
		//cout<<"Exit Price : "<<Price_In<<" , "<<Exit<<endl;
		//ACC.set_Loss(Exit/Pips);
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

void Order::Check_ORD_TakeProfit(double Price_In,int Mode_In,double TakeProfit_In,int BUY_SELL_Mode)
{

	TakeProfit_In=TakeProfit_In*Pips;
	if(Mode_In==1&&((Price_In-Price)>=TakeProfit_In)&&Price_In>Price&&BUY_SELL_Mode!=0) // Long TakePofit
	{
		//cout<<"----------------TAKE------PROFIT----------------------------"<<endl;
		ORD_Exit(Price_In,1,1);
		Mode=0;
	}	
	if(Mode_In==2&&(Price-Price_In)>=TakeProfit_In&&Price_In<Price)   // Short TakeProfit
	{
		ORD_Exit(Price_In,1,1);
		Mode=0;
	}
}

void Order::Check_ORD_StopLoss(double Price_In, int Mode_In,double StopLoss_In,int BUY_SELL_Mode)
{
	StopLoss_In=StopLoss_In*Pips;
	if(Mode_In==1&&((Price-Price_In)>=StopLoss_In)&&Price_In<Price&&BUY_SELL_Mode!=0) // Long StopLoss
	{
		//cout<<"----------------STOP-------LOSS---------------------"<<endl;
		ORD_Exit(Price_In,1,2);
		Mode=0;
	}	
	if(Mode_In==2&&(Price_In-Price)>=StopLoss_In&&Price<Price_In)  // Short StopLoss
	{
		ORD_Exit(Price_In,1,2);
		Mode=0;
	}
	
}






















