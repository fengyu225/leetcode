/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

#include "header.h"

bool isPowerOfFour(int num) {
    long n = num;
    int temp = 0x55555555;
    return n!=0 && (n|temp) == temp && (n&(n-1)) == 0;
}

int main(){
    cout<<isPowerOfFour(15)<<endl;
    cout<<isPowerOfFour(16)<<endl;
    return 0;
}
