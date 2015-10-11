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

<<<<<<< HEAD
void Account::set_ACC_Profit(double Profit_In)
=======
void Account::set_Profit(double Profit_In)
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
{
	Balance = Balance + Profit_In;
	set_ACC_Balance(Balance);
}

<<<<<<< HEAD
void Account::set_ACC_Loss(double Loss_In)
=======
void Account::set_Loss(double Loss_In)
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
{
	Balance = Balance - Loss_In;
	set_ACC_Balance(Balance);
}







