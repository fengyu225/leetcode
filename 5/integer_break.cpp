/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.
*/

#include "header.h"

int integerBreak(int n) {
    vector<int> arr(n+1, 1);
    for(int i=2; i<=n; i++){
        int temp = 1;
        for(int j=1; j<i; j++) temp = max(temp, max(j, arr[j])*(i-j));
        arr[i] = temp;
    }
    return arr[n];
}

int main(){
//    cout<<integerBreak(2)<<endl;
    //cout<<integerBreak(10)<<endl;
    cout<<integerBreak(6)<<endl;
    return 0;
}
