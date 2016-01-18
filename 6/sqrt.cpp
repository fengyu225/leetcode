/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include "header.h"

int mySqrt(int x) {
    if(x == 1) return 1;
    if(x == 0) return 0;
    long l = 1, r = x;
    while(l+1<r){
        long m = l+(r-l)/2;
        if(m*m>x) r = m-1;
        else l = m;
    }
    return r*r<x?r:l;
}

int main(){
    cout<<mySqrt(2147395599)<<endl;
    return 0;
}