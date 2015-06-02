#include "header.h"

int mySqrt(int x){
    if(x == 0 || x==1) return x;
    int l = 1, r=x;
    int m = (l+r+1)/2;
    while(l<r){
        m = (l+r+1)/2;
        if(m == x/m) return m;
        if(m<x/m) l=m;
        else r=m-1;
    }
    return l;
}

int main(){
//    printf("%.10f\n", mySqrt_f(4,0.00000000001f));
//    printf("%.10f\n", mySqrt_f(5,0.00000000001f));
//    printf("%d\n", mySqrt(5));
//    printf("%d\n", mySqrt(2));
//    printf("%d\n", mySqrt(0));
//    printf("%d\n", mySqrt(1));
//    printf("%d\n", mySqrt(16));
//    printf("%d\n", mySqrt(2147395599));
    printf("%d\n", mySqrt(0));
    printf("%d\n", mySqrt(1));
    printf("%d\n", mySqrt(2));
    printf("%d\n", mySqrt(3));
    printf("%d\n", mySqrt(4));
    printf("%d\n", mySqrt(5));
    printf("%d\n", mySqrt(6));
    printf("%d\n", mySqrt(7));
    printf("%d\n", mySqrt(8));
    printf("%d\n", mySqrt(9));
    printf("%d\n", mySqrt(10));
    return 0;
}
