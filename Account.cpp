#include "Account.h"

Account::Account()
{
    Counter=0;
}

Account::~Account()
{

}

void Account::set_ACC_ID()
{
    Counter++;
    ARRAY[Counter] = Counter;
    Counter = Counter;
    //return Counter;
}

void Account::set_ACC_Balance(double Balance_In)
{
    Balance = Balance_In;
}

void Account::set_ACC_Margin(int Margin_In)
{
    Margin = Margin_In;
}

int Account::get_ACC_ID()
{
	return ID;
}

double Account::get_ACC_Balance()
{
	return Balance;
}

double Account::get_ACC_Margin()
{
	return Margin;
}

void Account::set_Profit(double Profit_In)
{
	Balance = Balance + Profit_In;
	set_ACC_Balance(Balance);
}

void Account::set_Loss(double Loss_In)
{
	Balance = Balance - Loss_In;
	set_ACC_Balance(Balance);
}







