/*
Implement pow(x, n).
*/

#include "header.h"

double myPow_d(double x, long n){
    if(n == 0) return 1.0;
    if(n < 0) return 1.0/myPow_d(x, -n);
    double temp = x, res = 1.0;
    while(n){
        if((n&1) == 1) res*=temp;
        temp*=temp;
        n>>=1;
    }
    return res;
}

double myPow(double x, int n) {
    return myPow_d(x,(long)n);
}

int main(){
//    printf("%f\n", myPow(0.5, 2147483647));
    printf("%f\n", myPow(4.70975, 6));
    return 0;
}
