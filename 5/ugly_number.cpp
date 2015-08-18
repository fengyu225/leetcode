/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

#include "header.h"

//bool isUgly(int num) {
//    //slow ...
//    long n = num>=0?(long)num:(long)-1*(long)num;
//    vector<bool> checks(n+1, true);
//    for(long i=2; i<=sqrt(n); i++){
//        for(long x=2; x*i<=sqrt(n); x++)
//            checks[x*i] = false;
//    }
//    for(long i=6; i<=sqrt(n); i++){
//        if(checks[i] && num%i == 0) return false;
//    }
//    return true;
//}

bool isUgly(int num) {
    if(num<0) return false;
    long n = num>=0?(long)num:(long)-1*(long)num;
    if(n == 1) return true;
    while(n>=2 && n%2 == 0) n=n/2;
    while(n>= 5 && n%5 == 0) n=n/5;
    while(n>=3 && n%3 == 0) n=n/3;
    return n == 1;
}

int main(){
//    cout<<isUgly(6)<<endl;
//    cout<<isUgly(8)<<endl;
    cout<<isUgly(INT_MIN)<<endl;
//    cout<<isUgly(INT_MAX)<<endl;
    return 0;
}