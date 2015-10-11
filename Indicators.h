#ifndef INDICATORS_H
#define INDICATORS_H
#include <fstream>
#include <vector>
using namespace std;
class Indicators
{
    public:
        Indicators();
        ~Indicators();
        void IND_SMA(double*,double*,int,int); 
        void IND_EMA(double[][5],fstream*,double*,int,int,double*);
        void IND_ADX(double[][5],double*,int,int);
        void IND_RSI(double[][5],double*,int,int);
        void IND_DC(double[][5],fstream*,int,int,int,double);
        void IND_AUTOCORREL(double[][5],double*,int,int);
        double Absolute(double);
              
    private:

};

#endif // INDICATORS_H odify_array(int (&a)[10][10]
