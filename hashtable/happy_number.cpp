/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include "header.h"

int sumSquare(int n){
    int res = 0;
    while(n>9){
        int x = n-n/10*10;
        res += x*x;
        n/=10;
    }
    res += n*n;
    return res;
}

bool isHappy(int n){
    unordered_set<int> s;
    int curr = sumSquare(n);
    if(curr == 1) return true;
    while(curr != 1){
        if(s.find(curr) != s.end()) return false;
        s.insert(curr);
        curr = sumSquare(curr);
    }
    return true;
}

int main(){
    cout<<isHappy(9)<<endl;
    cout<<isHappy(19)<<endl;
    return 0;
}