#ifndef ORDER_H
#define ORDER_H


class Order
{
    public:
        Order();
        ~Order();
        void ORD_Buy(double,double); //ID,Price,Spread
        void ORD_Sell(double,double);
        void ORD_Exit(double,int,int);
        void ORD_TakeProfit(double,int);
        void ORD_StopLoss(double,int);    
        void set_ORD_Pip(int);
        void Check_ORD_TakeProfit(double,int,double,int);
        void Check_ORD_StopLoss(double,int,double,int);
        double get_ORD_Price();
        double get_ORD_Exit();
        double get_ORD_TakeProfit();
        double get_ORD_StopLoss();      
        double get_ORD_Spread();
        int get_ORD_TakeProfit_PIPS();
        int get_ORD_StopLoss_PIPS();
        int get_ORD_NumberofBUYS();
        int get_ORD_NumberofSELLS();
        int get_ORD_Mode();

    private:
    	double Pips;
    	int Orders;
        double Price,TakeProfit,StopLoss,Exit;
        int TAKEPROFIT_PIPS;
        int STOPLOSS_PIPS;
        int Mode;
        int BUY_Counter;
        int SELL_Counter;
        double Spread;
        double PipMode;
       
};

#endif
