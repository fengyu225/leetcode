/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

#include "header.h"

int rangeBitwiseAnd(int m, int n){
    int res = 0;
    for(int i=30; i>=0; i--){
        int x = 1<<i;
        if(n<x){
            res |= (0<<i);
        }
        else if(n>x){

        }
    }
}

int main(){
    return 0;
}