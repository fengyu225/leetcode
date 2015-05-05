#include "header.h"

int sqrt(int x){
    if(x==0 || x==1) return x;
    int l=1, r=x;
    while(l<r){
        int m = (l+r+1)/2;
        if(m == x/m) return m;
        if(m<x/m) l=m;
        else r=m-1;
    }
    return l;
}

int main(){
//    printf("%.10f\n", sqrt_f(4,0.00000000001f));
//    printf("%.10f\n", sqrt_f(5,0.00000000001f));
//    printf("%d\n", sqrt(5));
//    printf("%d\n", sqrt(2));
//    printf("%d\n", sqrt(0));
//    printf("%d\n", sqrt(1));
//    printf("%d\n", sqrt(16));
//    printf("%d\n", sqrt(2147395599));
    printf("%d\n", sqrt(0));
    printf("%d\n", sqrt(1));
    printf("%d\n", sqrt(2));
    printf("%d\n", sqrt(3));
    printf("%d\n", sqrt(4));
    printf("%d\n", sqrt(5));
    printf("%d\n", sqrt(6));
    printf("%d\n", sqrt(7));
    printf("%d\n", sqrt(8));
    printf("%d\n", sqrt(9));
    printf("%d\n", sqrt(10));
    return 0;
}
