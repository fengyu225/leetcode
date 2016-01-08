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
        auto f_f = from.find(t[i]);
        auto t_f = to.find(s[i]);
        if(f_f != from.end() && t_f != to.end() && from[t[i]] == s[i] && to[s[i]] == t[i]) continue;
        else if(f_f == from.end() && t_f == to.end()){
            from[t[i]] = s[i];
            to[s[i]] = t[i];
        }
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