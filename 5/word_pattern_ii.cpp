/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

#include "header.h"

bool search(string& pattern, string& str, int p_sz, int s_sz, int p_curr, int s_curr, unordered_map<char,string>& m){
    if(s_curr == s_sz){
        if(p_curr == p_sz) return true;
        return false;
    }
    if(p_curr == p_sz) return false;
    for(int i=s_curr; i<s_sz; i++){
        
    }
    return false;
}

bool wordPatternMatch(string pattern, string str) {
    int p_sz = pattern.length(), s_sz = str.length();
    unordered_map<char,string> m;
    return search(pattern, str, p_sz, s_sz, 0, 0, m);
}

int main(){
    cout<<wordPatternMatch("abab", "redblueredblue")<<endl;
    cout<<wordPatternMatch("aaaa", "asdasdasdasd")<<endl;
    cout<<wordPatternMatch("aabb", "xyzabcxzyabc")<<endl;
    return 0;
}