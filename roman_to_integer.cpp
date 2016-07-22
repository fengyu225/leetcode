/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/


#include "header.h"

unordered_map<char,int> m = {
    {'M',1000},
    {'D',500},
    {'C',100},
    {'L',50},
    {'X',10},
    {'V',5},
    {'I',1}
};

unordered_map<char,int> limits = {    
    {'M',4},
    {'D',2},
    {'C',4},
    {'L',2},
    {'X',4},
    {'V',2},
    {'I',4}
};

int romanToInt(string s){
    //check invalid input
    int sz = s.length();
    if(sz == 0) return 0;
    int res = 0;
    for(int i=0; i<sz; i++){
        char c = s[i];
        if(m.find(c) == m.end()) return -1;
        if(i>0 && m[c]>m[s[i-1]]) res += m[c]-2*m[s[i-1]];
        else if(i>0 && m[c]==m[s[i-1]] && limits[c]+i-2<sz){
            bool temp = true;
            for(int j=i; j<=limits[c]+i-2; j++)
                if(s[j] != s[j-1]){
                    temp = false;
                    break;
                }
            if(temp) return -1;
            res+=m[c];
        }
        else res+=m[c];
    }
    return res;
}

int main(){
    cout<<romanToInt("CXXIII")<<endl;
    cout<<romanToInt("C")<<endl;
    cout<<romanToInt("CIIII")<<endl;
    return 0;
}