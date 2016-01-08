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
    unordered_map<char,char> from, to;
    for(int i=0; i<sz; i++){
        if(from.find(s[i]) == from.end() && to.find(t[i]) == to.end()){
            from[s[i]] = t[i];
            to[t[i]] = s[i];
        }
        else if(from.find(s[i]) != from.end() && to.find(t[i]) != to.end() && from[s[i]] == t[i] && to[t[i]] == s[i]) continue;
        else return false;
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