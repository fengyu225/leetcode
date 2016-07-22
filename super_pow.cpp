/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:
a = 2
b = [3]

Result: 8

Example 2:
a = 2
b = [1,0]

Result: 1024
*/

#include "header.h"

int superPow(int a, vector<int>& b) {
    int sz = b.size();
    if(sz == 0) return 1;
    int res = 1;
    for(int i=0; i<b[sz-1]; i++) res=((res%1337) * (a%1337))%1337;
    b.erase(b.end()-1);
    int l = superPow(a, b);
    int temp = 1;
    for(int i=0; i<10; i++) temp=((temp%1337) * (l%1337))%1337;
    res = (res*temp)%1337;
    return res;
}

int main(){
    vector<int> b = {1, 0, 0, 1, 0, 0, 1, 0, 0};
    cout<<superPow(2, b)<<endl;
    return 0;
}
