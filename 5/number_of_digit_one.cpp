/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

#include "header.h"

int countDigitOne(int n);

int countDigitOne(int n, int x){
    if(n == 0) return 0;
    if(n<10 || x==1) return 1;
    if(n/x == 1) return n-n/x*x+1+countDigitOne(n-n/x*x)+countDigitOne(x-1);
    return x+n/x*countDigitOne(x-1)+countDigitOne(n-n/x*x);
}

int countDigitOne(int n) {
    if(n <= 0) return 0;
    int x = 1, y=n;
    for(;y>=10;x*=10,y/=10);
    return countDigitOne(n, x);
}

int main(){
    //cout<<countDigitOne(20)<<endl;
    //cout<<countDigitOne(13)<<endl;
    cout<<countDigitOne(1011)<<endl;
    //cout<<countDigitOne(212)<<endl;
    //cout<<countDigitOne(999)<<endl;
    //cout<<countDigitOne(9999)<<endl;
    return 0;
}