/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include "header.h"

int count(int s, int n){
    //count number of appearence of n in s!
    int res = 0;
    while(s>=n){
        res+=s/n;
        s/=n;
    }
    return res;
}

int trailingZeroes(int n) {
    return min(count(n,2),count(n,5));
}

int main(){
    cout<<trailingZeroes(10)<<endl;
//    cout<<count(26,5)<<endl;
    return 0;
}