/*
Given an integer, write a function to determine if it is a power of two.
*/

#include "header.h"

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    return (n&(n-1)) == 0;
}

int main(){
    cout<<isPowerOfTwo(0)<<endl;
    return 0;
}