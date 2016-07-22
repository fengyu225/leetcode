/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
#include "header.h"

bool isIsomorphic(string s, string t) {
    int sz = s.length();
    if(sz != t.length()) return false;
    if(sz == 0) return true;
    vector<int> source(256,-1);
    vector<int> dest(256,-1);
    for(int i=0; i<sz; i++){
        if(source[s[i]] != -1 && source[s[i]]!=t[i] || dest[t[i]]!=-1 && dest[t[i]]!=s[i]) return false;
        source[s[i]] = t[i];
        dest[t[i]] = s[i];
    }
    return true;
}

int main(){
    cout<<isIsomorphic("ab","ca")<<endl;
    cout<<isIsomorphic("egg","add")<<endl;
    cout<<isIsomorphic("foo","bar")<<endl;
    cout<<isIsomorphic("paper","title")<<endl;
    return 0;
}