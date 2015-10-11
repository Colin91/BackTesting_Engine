#ifndef ORDER_H
#define ORDER_H


class Order
{
    public:
        Order();
        ~Order();
<<<<<<< HEAD
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
=======
        double ORD_Buy(double,double,int); //ID,Price,Spread
        double ORD_Sell(double,double);
        void ORD_Exit(double,int,int);
        double ORD_TakeProfit(double,int);
        double ORD_StopLoss(double,int);
        double get_ORD_Price();
        double get_ORD_Exit();
        double get_ORD_TakeProfit();
        double get_ORD_StopLoss();
        int get_ORD_Mode();
        double get_ORD_Spread();
        void set_ORD_Pip(int);
        void Check_ORD_TakeProfit(double,int,double,int);
        void Check_ORD_StopLoss(double,int,double,int);
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5

    private:
    	double Pips;
    	int Orders;
        double Price,TakeProfit,StopLoss,Exit;
<<<<<<< HEAD
        int TAKEPROFIT_PIPS;
        int STOPLOSS_PIPS;
        int Mode;
        int BUY_Counter;
        int SELL_Counter;
        double Spread;
        double PipMode;
       
=======
        int Mode;
        int Counter;
        double Spread;
        double PipMode;
       
        
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
};

#endif
