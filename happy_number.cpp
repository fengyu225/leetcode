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

bool isHappy(int n){
    if(n == 0) return false;
    int temp = n;
    unordered_set<int> s;
    while(s.find(n) == s.end()){
        temp = 0;
        s.insert(n);
        while(n){
            temp += pow(n%10,2);
            n/=10;
        }
        if(temp == 1) return true;
        n = temp;
    }
    return false;
}

int main(){
    cout<<isHappy(9)<<endl;
    return 0;
}