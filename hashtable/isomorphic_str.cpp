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
    if(s.length() != t.length()) return false;
    int sz = s.length();
    if(sz != t.length()) return false;
    unordered_map<char,char> from;
    unordered_map<char,char> to;
    for(int i=0; i<sz; i++){
        if(to.find(s[i])!=to.end() && to[s[i]] != t[i] || from.find(t[i]) != from.end() && from[t[i]] != s[i])
            return false;
        from[t[i]] = s[i];
        to[s[i]] = t[i];
    }
    return true;
}

int main(){
    cout<<isIsomorphic("ab","aa")<<endl;
    //cout<<isIsomorphic("ab","ca")<<endl;
    //cout<<isIsomorphic("egg","add")<<endl;
    //cout<<isIsomorphic("foo","bar")<<endl;
    //cout<<isIsomorphic("paper","title")<<endl;
    return 0;
}