#ifndef ORDER_H
#define ORDER_H


class Order
{
    public:
        Order();
        ~Order();
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

    private:
    	double Pips;
    	int Orders;
        double Price,TakeProfit,StopLoss,Exit;
        int Mode;
        int Counter;
        double Spread;
        double PipMode;
       
        
};

#endif
