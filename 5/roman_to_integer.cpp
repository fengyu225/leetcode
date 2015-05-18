/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;
*/

#include "header.h"

int romanToInt(string s){
    if(s.length() == 0) return 0;
    unordered_map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int res = 0, sz = s.length(), pre=0, curr=1;
    while(curr<sz){
        if(m[s[curr]]<m[s[pre]])
            res += 
    } 
    return res;
}

int main(){
    cout<<romanToInt("CXXIII")<<endl;
    return 0;
}