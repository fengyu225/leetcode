/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

#include "header.h"

int nthUglyNumber(int n) {
    deque<int> q;
    q.push_back(1);
    int two = 0, three = 0;
    for(int i=2; i<=n; i++){
        int temp = min(2*q[two], min(3*q[three], 5*q.front()));
        q.push_back(temp);
        if(q[two]*2 == temp) two++;
        if(q[three]*3 == temp) three++;
        if(q.front()*5 == temp){
            q.pop_front();
            two--;
            three--;
        }
    }
    return q.back();
}

int main(){
//    cout<<nthUglyNumber(6)<<endl;
//    cout<<nthUglyNumber(8)<<endl;
//    cout<<nthUglyNumber(10)<<endl;
    for(int i=1; i<=10; i++) cout<<nthUglyNumber(i)<<endl;
    return 0;
}