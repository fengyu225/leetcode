/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

#include "header.h"

//int nthUglyNumber(int n) {
//    //using set
//    set<long> s;
//    s.insert(1);
//    long res;
//    for(int i=0; i<n; i++){
//        res = *s.begin();
//        s.insert(res*(long)2);
//        s.insert(res*(long)3);
//        s.insert(res*(long)5);
//        s.erase(s.begin());
//    }
//    return res;
//}

//int nthUglyNumber(int n) {
//    //needs more space
//    deque<int> q;
//    int i_2 = 0, i_3 = 0, i_5 = 0;
//    int curr = 2;
//    q.push_back(1);
//    while(curr<=n){
//        int temp = min(q[i_2]*2, min(q[i_3]*3, q[i_5]*5));
//        q.push_back(temp);
//        if(q[i_2]*2<=temp) i_2++;
//        if(q[i_3]*3<=temp) i_3++;
//        if(q[i_5]*5<=temp) i_5++;
//        curr++;
//    }
//    return q.back();
//}

int nthUglyNumber(int n) {
    //faster and less space
    deque<int> q;
    int i_2 = 0, i_3 = 0, i_5 = 0;
    q.push_back(1);
    int curr = 2;
    while(curr<=n){
        int temp = min(q[i_2]*2, min(q[i_3]*3, q[i_5]*5));
        q.push_back(temp);
        if(q[i_2]*2 == temp) i_2++;
        if(q[i_3]*3 == temp) i_3++;
        if(q[i_5]*5 == temp){
            q.pop_front();
            i_2--;
            i_3--;
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