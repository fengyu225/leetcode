#include "header.h"

double pow_(double x, int n){
    if(x==0)
        return n==0?1:0;
    if(n==0) return 1;
    int s = n<0?-1:1;
    n = abs(n);
    printf("%d\n", n);
    double res = 1;
    double np = x;
    while(n>0){
        if(n%2==1){
            res *= np;
        }
        np *= np;
        n = n>>1;
    }
    return s>0?res:1.0/res;
}

int main(){
    printf("%f\n", pow_(0.5, -2147483648));
    return 0;
}
