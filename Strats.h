#ifndef STRATS_H
#define STRATS_H
<<<<<<< HEAD
#include <fstream>
#include <string>
#include <sstream>
#include <istream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "Indicators.h"
#include "OrderList.h"
#include "Order.h"
#include "Account.h"
#include "Order.h"
#include "Strats.h"
=======
#include "Indicators.h"
#include "OrderList.h"
#include "Order.h"
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5

class Strats
{
    public:
        Strats();
<<<<<<< HEAD
        ~Strats();
        void TRINDIC(double[][5],int,double*,double*,double[]); //TicketNumber
        int STR_Condition(double C1,double C2,int Flag);

    private:
    	int Flag_To_Be_EXEC;
=======
        int TRINDIC(int); //TicketNumber

    private:
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
};

#endif // STRATS_H
