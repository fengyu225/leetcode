/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False
*/

#include "header.h"

int sqrt(int num){
    int l = 1, r = num;
    while(l+1<r){
        long temp = ((long)l+(long)r)/2;
        if(temp*temp == num) return temp;
        else if(temp*temp<num) l = temp;
        else r = temp-1;
    }
    return r*r<=num?r:l;
}

bool isPerfectSquare(int num) {
    int s = sqrt(num);
    return s == (double) num/s;
}

int main(){
    cout<<isPerfectSquare(INT_MAX)<<endl;
    //cout<<isPerfectSquare(16)<<endl;
    //cout<<isPerfectSquare(14)<<endl;
    return 0;
}
