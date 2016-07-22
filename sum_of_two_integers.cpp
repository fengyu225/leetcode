/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

#include "header.h"

int getSum(int a, int b) {
    int res = 0, carry = 0;
    while(b){
        res = a^b;
        carry = (a&b)<<1;
        a = res;
        b = carry;
    }
    return a;
}

int main(){
    cout<<getSum(-1, 1)<<endl;
    return 0;
}
