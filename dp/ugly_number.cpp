/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

#include "header.h"

bool isUgly(int num) {
    if(num<=0) return false;
    if(num == 1) return true;
    num = (long)abs(num);
    for(;num >=2 && num%2 == 0; num /=2);
    for(;num >=3 && num%3 == 0; num /=3);
    for(;num >=5 && num%5 == 0; num /=5);
    return num == 1;
}

int main(){
//    cout<<isUgly(6)<<endl;
//    cout<<isUgly(8)<<endl;
    cout<<isUgly(INT_MIN)<<endl;
//    cout<<isUgly(INT_MAX)<<endl;
    return 0;
}