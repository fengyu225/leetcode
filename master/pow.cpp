#include "header.h"

double pow_(double x, int n){
    if(x==0)
        return n==0?1:0;
    if(n==0) return 1;
    if(n<0){
        if(n==INT_MIN) return 1.0/(pow(x,INT_MAX)*x);
        return 1.0/pow(x,-n);
    }
    double res = 1;
    double np = x;
    while(n>0){
        if(n%2==1){
            res *= np;
        }
        np *= np;
        n = n>>1;
    }
    return res;
}

int main(){
    printf("%f\n", pow_(0.5, 2147483647));
    return 0;
}
