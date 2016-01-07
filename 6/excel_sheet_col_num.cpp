/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

#include "header.h"

int titleToNumber(string s){
    int res = 0;
    for(int i=0; i<s.length(); i++){
        res *= 26;
        res += (s[i]-'A')+1;
    }
    return res;
}

int main(){
    cout<<titleToNumber("AB")<<endl;
    return 0;
}