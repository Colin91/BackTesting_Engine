#include <string.h>
#include <iostream>
#include "OrderList.h"
using namespace std;
/*
Errors:
	


*/

OrderList::OrderList(Order* Order_In)
{
	Counter=0;
	ORD_ARR = Order_In;
}

OrderList::~OrderList()
{

}

void OrderList::ORDL_Add(Order Order_In)
{
	ORD_ARR[Counter]=Order_In;
	Counter++;
}

void OrderList::ORDL_ListArray()
{
	for(int i=0;i<Counter;i++)
	{
		cout<<"Price : , "<<ORD_ARR[i].get_ORD_Price()<<endl;
		cout<<"Limit : , "<<ORD_ARR[i].get_ORD_TakeProfit()<<endl;
		cout<<"StopL : , "<<ORD_ARR[i].get_ORD_StopLoss()<<endl;
		cout<<"Exit  : , "<<ORD_ARR[i].get_ORD_Exit()<<endl;
		cout<<"-------------------------------"<<endl;
	}	
}

