/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/

#include "header.h"

int countNumbersWithUniqueDigits(int n){
    if(n == 0) return 1;
    vector<int> arr(n+1, 0);
    arr[1] = 10;
    int last = 9;
    for(int i=2; i<=n; i++){
        last *= (9-i+2);
        arr[i] = arr[i-1]+last;
    }
    return arr[n];
}

int main(){
    cout<<countNumbersWithUniqueDigits(2)<<endl;
    cout<<countNumbersWithUniqueDigits(3)<<endl;
    cout<<countNumbersWithUniqueDigits(4)<<endl;
    return 0;
}
