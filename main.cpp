#include <fstream>
#include <string>
#include <sstream>
#include <istream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Indicators.h"
#include "Account.h"
#include "Account.cpp"
#include "Order.h"
#include "Strats.h"
#include "OrderList.h"

using namespace std;

//DataSet Range 01/01/2013 - 31/05/2015 - Imported from Duckoscopy.com

int main()
{
	int Counter=0;
	int BUY_MODE=0;
    Indicators IND;
    Order ORD;
    Order* ARRAY_ORDERS = new Order[1000];
    OrderList ORDL(ARRAY_ORDERS);
    Order ORD1;
 
  		
	double TP = 100;
	double SL = 100;	
	double Spread=0;
    double Price,TakeProfit,StopLoss,Exit;
    int Period=3;
    fstream FP;
    int Range=15;
    string buffer;
    //FP.open("EURUSD5MINS.txt",ios::in);
    FP.open("EURUSD_1HR_01.03.2013_31.05.2015(Cleaned).txt",ios::in);
    double ARRAY_PRICE[Range][4]; //OHLC
    double ARRAY_SMA[Range];
    double ARRAY_EMA[Range];
    double ARRAY_ADX[Range];
    double ARRAY_RSI[Range];
    double ARRAY_DC[Range];
    double CONV_To_DOUBLE=0;
    double OPEN=0,HIGH=0,LOW=0,CLOSE=0;
    char BufferPrice[7];

    
    /* 
    To Note : File has OPEN,HIGH,LOW,CLOSE Prices in a 2-D Matrix
    Prices streamed from the file need to be partitioned, converted to double and inputted in the respective column
    ARRAY_PRICE[0][0] = OPEN  /Range of characters in Row = 0-6
    ARRAY_PRICE[1][0] = HIGH  /Range of characters in Row = 8-14
    ARRAY_PRICE[2][0] = LOW   /Range of characters in Row = 16-22
    ARRAY_PRICE[3][0] = CLOSE /Range of characters in Row = 23-31
    xxxxxxx xxxxxxx xxxxxxx xxxxxxx
    */
    for(int i=0;i<Range;i++)
    {
        getline(FP,buffer);
        //OPEN
        for(int j=6;j>=0;j--)
        {
        	BufferPrice[j] = buffer[j];   	
        }
        istringstream sa(BufferPrice);
        sa>>OPEN;
        ARRAY_PRICE[i][0]=OPEN;
		//HIGH
        for(int j=14;j>=8;j--)
        {
        	BufferPrice[j-8] = buffer[j];   	
        }
        istringstream sb(BufferPrice);
        sb>>HIGH;
        ARRAY_PRICE[i][1]=HIGH;
        //LOW
        for(int j=22;j>=16;j--)
        {
        	BufferPrice[j-16] = buffer[j];   	
        }
        istringstream sc(BufferPrice);
        sc>>LOW;
        ARRAY_PRICE[i][2]=LOW;
        //CLOSE
        for(int j=31;j>=23;j--)
        {
        	BufferPrice[j-23] = buffer[j];   	
        }
        istringstream sd(BufferPrice);
        sd>>CLOSE;
        ARRAY_PRICE[i][3]=CLOSE;
    }
    /*
    cout<<ARRAY_PRICE[0][3]<<endl;
    cout<<ARRAY_PRICE[1][3]<<ARRAY_PRICE[1][3]-ARRAY_PRICE[0][3]<<endl;
    cout<<ARRAY_PRICE[2][3]<<ARRAY_PRICE[2][3]-ARRAY_PRICE[1][3]<<endl;
    cout<<ARRAY_PRICE[3][3]<<ARRAY_PRICE[3][3]-ARRAY_PRICE[2][3]<<endl;
    cout<<ARRAY_PRICE[4][3]<<ARRAY_PRICE[4][3]-ARRAY_PRICE[3][3]<<endl;
    */
    FP.close();
          
    //IND.IND_SMA(ARRAY_PRICE,ARRAY_SMA,Period,Range);
    //IND.IND_EMA(ARRAY_PRICE,ARRAY_EMA,Period,Range);
    IND.IND_ADX(ARRAY_PRICE,ARRAY_ADX,Period,Range);
    //IND.IND_RSI(ARRAY_PRICE,ARRAY_RSI,Period,Range);
    //IND.IND_DC(ARRAY_PRICE,ARRAY_DC,Period,Range,1,1);
    
    /*	
    ORD1.set_ORD_Pip(0); 
    for(int i=Period;i<Range;i++)
    {	
		//if(ARRAY_SMA[i]>ARRAY_CLOSE[i]&&BUY_MODE==0)
		//{
			BUY_MODE = 1;
			
			if(BUY_MODE==1)
			{
					
					Price = ORD1.ORD_Buy(ARRAY_PRICE[i][0],Spread,Counter);
					
					TakeProfit = ORD1.ORD_TakeProfit(TP,1);
					StopLoss = ORD1.ORD_StopLoss(SL,1);
					ORDL.ORDL_Add(ORD1);
					Counter++;	
					//cout<<"Open Position : Profit/Loss at : "<<(ARRAY_CLOSE[i]-ORD1.get_ORD_Price())/0.0001;
					//cout<<"   ::   Current Price : "<<ARRAY_CLOSE[i]<<" , Entry Price "<<ORD1.get_ORD_Price();
					//cout<<" , Order Mode "<<ORD1.get_ORD_Mode()<<endl;
					//cout<<" i : "<<i<<endl;
					
			}

		//}
		
		if(ORD1.get_ORD_Mode()==0)
		{
			BUY_MODE=0;
			
		}
		ORD1.Check_ORD_TakeProfit(ARRAY_PRICE[i][0],1,TP,BUY_MODE);
		ORD1.Check_ORD_StopLoss(ARRAY_PRICE[i][0],1,SL,BUY_MODE);	
	
	}
	*/
		

    return 0;
}



