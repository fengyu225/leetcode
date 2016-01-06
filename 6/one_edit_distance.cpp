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
    if(abs(s_sz-t_sz)>=2) return false;
    if(t_sz == 0) return s_sz == 1;
    int s_curr = 0, t_curr = 0, found = 0;
    while(s_curr<s_sz && t_curr<t_sz){
        if(s[s_curr] != t[t_curr]){
            if(found>=1) return false;
            found++;
            if(s_sz == t_sz) t_curr++;
        }
        else t_curr++;
        s_curr++;
    }
    return (s_curr == s_sz && t_curr == t_sz && found == 1) || (found == 0 && s_sz-s_curr==1);
}

int main(){
//    cout<<isOneEditDistance("", "")<<endl;
//    cout<<isOneEditDistance("a", "")<<endl;
//    cout<<isOneEditDistance("abc", "ab")<<endl;
//    cout<<isOneEditDistance("abcd", "abe")<<endl;
    cout<<isOneEditDistance("abcd", "abed")<<endl;
    cout<<isOneEditDistance("a", "A")<<endl;
    cout<<isOneEditDistance("a", "ba")<<endl;
    cout<<isOneEditDistance("ab", "acb")<<endl;
    return 0;
}