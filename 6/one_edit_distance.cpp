/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

#include "header.h"

bool isOneEditDistance(string s, string t){
    if(s == t) return false;
    if(s.length()<t.length()){
        string temp = s;
        s = t;
        t = temp;
    }
    int s_sz = s.length();
    int t_sz = t.length();
}

int main(){
    cout<<isOneEditDistance("", "")<<endl;
    cout<<isOneEditDistance("a", "")<<endl;
    cout<<isOneEditDistance("abc", "ab")<<endl;
    cout<<isOneEditDistance("abcd", "abe")<<endl;
    cout<<isOneEditDistance("abcd", "abed")<<endl;
    return 0;
}