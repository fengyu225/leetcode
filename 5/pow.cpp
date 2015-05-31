/*
Implement pow(x, n).
*/

#include "header.h"

double myPow(double x, int n){
    if(x == 0) return n==0?1:0;
    if(n == 0) return 1;
    if(n<0){
        if(n == INT_MIN) return 1/(x*myPow(x,INT_MAX));
        else return 1/myPow(x,-n);
    }
    double res = 1.0;
    double np = x;
    while(n){
        if((n&1)==1)
            res *= np;
        np *= np;
        n>>=1;
    }
    return res;
}

int main(){
    printf("%f\n", myPow(0.5, 2147483647));
    //printf("%f\n", myPow(2,3));
    return 0;
}
