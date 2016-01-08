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
    if(n == 1) return true;
    unordered_set<int> st;
    while(st.find(n) == st.end()){
        st.insert(n);
        int temp = 0, x = n;
        while(x){
            temp += pow(x%10,2);
            x/=10;
        }
        if(temp == 1) return true;
        n = temp;
    }
    return false;
}

int main(){
    cout<<isHappy(19)<<endl;
    return 0;
}