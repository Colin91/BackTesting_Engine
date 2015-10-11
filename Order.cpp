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

<<<<<<< HEAD
=======

>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
Order::Order() 
{
	Mode=0;
}


Order::~Order()
{
	
}

<<<<<<< HEAD
//This is straightfoward, for Major currencies pip value is 0.0001 and for YEN it is 0.01

=======
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
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

<<<<<<< HEAD
/*
	Input Price of Entry
	Deduct Spread from Price
	Set Price
*/
void Order::ORD_Buy(double Price_In,double Spread_In) //0 - Cash, 1 - Buy, 2 - Sell
{
	double ReturnPrice=0.0;
	//cout<<Price_In<<endl;
=======

double Order::ORD_Buy(double Price_In,double Spread_In,int Counter_In) //0 - Cash, 1 - Buy, 2 - Sell
{
	double ReturnPrice=0.0;
	//cout<<Counter_In<<endl;
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
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
<<<<<<< HEAD
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
=======
		 	//cout<<"Mode "<<Mode<<endl;
			Spread=Spread_In*0.0001;
			Price=Price_In-Spread;
			ReturnPrice = Price;	
		 }
	return ReturnPrice;
				
}

double Order::ORD_Sell(double Price_In,double Spread_In)
{

>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
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
<<<<<<< HEAD
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
=======
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

>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
		if(Price>0)
		{
			if(Pips_In<0)
			{
				cout<<"ERR_ORD_02 - Invalid Take Profit"<<endl;
			}	
			else
			{
<<<<<<< HEAD
				if(Mode==1) //TakeProfit
=======
				if(Mode==1)
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
				{
					Pips_In=Pips_In*Pips;
			 		Price_Out = Price + Pips_In;
			 		TakeProfit = Price_Out;
				}
	
<<<<<<< HEAD
				if(Mode==2) //StopLoss
=======
				if(Mode==2)
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
				{
					Pips_In=Pips_In*Pips;
					Price_Out = Price - Pips_In;
					TakeProfit = Price_Out;
				}
<<<<<<< HEAD
=======
	
				
		
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
			}
		}
		else
		{
			cout<<"ERR_ORD_05 - Invalid Price"<<endl;
		}
<<<<<<< HEAD
}

/*
	This Order is set at the option of the trader. 1 order at a time can be set.
	However Multiple Orders can be created by creating Multiple Objects.
*/
void Order::ORD_StopLoss(double Pips_In,int Mode_In)
{
	double Price_Out=0.0;
	STOPLOSS_PIPS = Pips_In;
=======

	return TakeProfit;
}

double Order::ORD_StopLoss(double Pips_In,int Mode_In)
{
	double Price_Out=0.0;
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
		if(Price>0)
		{
			if(Pips_In<0)
			{
				cout<<"ERR_ORD_03 - Invalid Stop Loss"<<endl;
			}	
			else
			{
<<<<<<< HEAD
				if(Mode==1) //TakeProfit
=======
				if(Mode==1)
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
				{
					Pips_In=Pips_In*Pips;
			 		Price_Out = Price - Pips_In;
			 		StopLoss = Price_Out;
				}
	
<<<<<<< HEAD
				if(Mode==2) //StopLoss
=======
				if(Mode==2)
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
				{
					Pips_In=Pips_In*Pips;
					Price_Out = Price + Pips_In;
					StopLoss = Price_Out;
				}
<<<<<<< HEAD
=======
				
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
			}
		}
		else
		{
			cout<<"ERR_ORD_05 - Invalid Price"<<endl;
		}
<<<<<<< HEAD
}

/*
	This is the final function for the trade.
	Exit Price is defined
*/
=======

	return StopLoss;
}
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5

void Order::ORD_Exit(double Price_In,int Mode_In,int OrderType_In)
{
	double Price_Out;
	if(Mode_In==0)
	{
		cout<<"No Order Placed"<<endl;
	}
<<<<<<< HEAD
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
	
=======
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

>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
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

<<<<<<< HEAD
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
=======
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



















>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5



