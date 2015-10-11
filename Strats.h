#ifndef STRATS_H
#define STRATS_H
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

class Strats
{
    public:
        Strats();
        ~Strats();
        void TRINDIC(double[][5],int,double*,double*,double[]); //TicketNumber
        int STR_Condition(double C1,double C2,int Flag);

    private:
    	int Flag_To_Be_EXEC;
};

#endif // STRATS_H
