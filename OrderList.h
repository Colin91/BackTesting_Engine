#ifndef ORDERLIST_H
#define ORDERLIST_H
#include "Order.h"

class OrderList
{
	public:
	
		OrderList(Order*); //array,Counter
		~OrderList();
		void ORDL_Add(Order);
		void ORDL_Remove(Order);
		void ORDL_IncreaseArray();
		void ORDL_ListArray();
	
	private:
		int ID;
		int Size;
		int Counter;
		Order ORD;
		Order* ORD_ARR;
		
};

#endif
