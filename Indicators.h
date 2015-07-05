#ifndef INDICATORS_H
#define INDICATORS_H


class Indicators
{
    public:
        Indicators();
        void IND_EMA(double[][4],double*,int,int); //double Array,Period
        void IND_SMA(double[][4],double*,int,int);
        void IND_ADX(double[][4],double*,int,int);
        void IND_RSI(double[][4],double*,int,int);
        void IND_DC(double[][4],double*,int,int,int,int);
        void IND_AUTOCORREL(double[][4],double*,int,int);
        double Absolute(double);
              
    private:

};

#endif // INDICATORS_H odify_array(int (&a)[10][10]
