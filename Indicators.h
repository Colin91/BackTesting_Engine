#ifndef INDICATORS_H
#define INDICATORS_H
<<<<<<< HEAD
#include <fstream>
#include <vector>
using namespace std;
=======


>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
class Indicators
{
    public:
        Indicators();
<<<<<<< HEAD
        ~Indicators();
        void IND_SMA(double*,double*,int,int); 
        void IND_EMA(double[][5],fstream*,double*,int,int,double*);
        void IND_ADX(double[][5],double*,int,int);
        void IND_RSI(double[][5],double*,int,int);
        void IND_DC(double[][5],fstream*,int,int,int,double);
        void IND_AUTOCORREL(double[][5],double*,int,int);
=======
        void IND_EMA(double[][4],double*,int,int); //double Array,Period
        void IND_SMA(double[][4],double*,int,int);
        void IND_ADX(double[][4],double*,int,int);
        void IND_RSI(double[][4],double*,int,int);
        void IND_DC(double[][4],double*,int,int,int,int);
        void IND_AUTOCORREL(double[][4],double*,int,int);
>>>>>>> 212ac0121b43f3ae3a6ffe37a2cc08f8d9132fe5
        double Absolute(double);
              
    private:

};

#endif // INDICATORS_H odify_array(int (&a)[10][10]
