/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

#include "header.h"

int nthUglyNumber(int n) {
    if(n == 1) return 1;
    int curr = 2;
    deque<int> q;
    int i2=0, i3=0, i5=0;
    q.push_back(1);
    while(curr<=n){
        int temp = min(q[i2]*2, min(q[i3]*3, q[i5]*5));
        q.push_back(temp);
        if(temp%2 == 0) i2++;
        if(temp%3 == 0) i3++;
        if(temp%5 == 0){
            q.pop_front();
            i2--;
            i3--;
        }
        curr++;
    }
    return q.back();
}

int main(){
    cout<<nthUglyNumber(6)<<endl;
    cout<<nthUglyNumber(8)<<endl;
    cout<<nthUglyNumber(10)<<endl;
    return 0;
}