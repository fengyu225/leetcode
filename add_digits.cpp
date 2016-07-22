/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

#include "header.h"

int addDigits(int num){
    //return num-9*((num-1)/9);
    //If an integer is like 100a+10b+c, then (100a+10b+c)%9=(a+99a+b+9b+c)%9=(a+b+c)%9
    return num==0?0:(num%9==0)?9:num%9;
}

int main(){
    cout<<addDigits(38)<<endl;
    return 0;
}