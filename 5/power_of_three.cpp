/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

#include "header.h"

bool isPowerOfThree(int n) {
    if(!n) return false;
    double a,b;
    a = modf((log10(n)/log10(3)), &b);
    return a==0;
}

int main(){
    cout<<isPowerOfThree(1)<<endl;
    cout<<isPowerOfThree(9)<<endl;
    cout<<isPowerOfThree(27)<<endl;
    cout<<isPowerOfThree(45)<<endl;
    return 0;
}