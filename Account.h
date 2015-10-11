#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
    public:
        Account(); 
        ~Account();
        void set_ACC_ID(); //new account
        void set_ACC_Balance(double);
<<<<<<< HEAD
        void set_ACC_Profit(double);
        void set_ACC_Loss(double);
=======
        void set_Profit(double);
        void set_Loss(double);
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
        void set_ACC_Margin(int);
        int get_ACC_ID();
        double get_ACC_Balance();
        double get_ACC_Margin();
        
    private:
    	int *ARRAY;
        int Counter;
        double Balance;
        int ID;
        int Margin;
};

#endif // ACCOUNT_H
