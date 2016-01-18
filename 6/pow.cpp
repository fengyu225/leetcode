/*
Implement pow(x, n).
*/

#include "header.h"

double myPow(double x, long n){
    if(n == 0) return 1;
    if(n<0) return 1.0/myPow(x,-n);
    if(n == 1) return x;
    double res = 1.0, np = x;
    while(n){
        if(n&1) res*=np;
        np*=np;
        n>>=1;
    }
    return res;
}

double myPow(double x, int n) {
    return myPow(x,(long)n);
}

int main(){
    printf("%f\n", myPow(0.5, 2147483647));
    //printf("%f\n", myPow(2,3));
    return 0;
}
