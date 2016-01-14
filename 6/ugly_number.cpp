/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

#include "header.h"

bool isUgly(int num) {
    if(num == 1) return true;
    if(num<0) return false;
    long n = (long)num;
    while(n>=2 && n%2 == 0) n/=2;
    while(n>=3 && n%3 == 0) n/=3;
    while(n>=5 && n%5 == 0) n/=5;
    return n == 1;
}

int main(){
//    cout<<isUgly(6)<<endl;
//    cout<<isUgly(8)<<endl;
    cout<<isUgly(INT_MIN)<<endl;
//    cout<<isUgly(INT_MAX)<<endl;
    return 0;
}