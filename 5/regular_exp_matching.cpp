/*
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include "header.h"

bool isMatch(string& s, int s_start, int s_end, string& p, int p_start, int p_end){
    if(p_start>p_end) return s_start>s_end;
    if(p_start == p_end) return s_start == s_end && (p[p_start] == '.' || p[p_start] == s[s_start]);
    if(p[p_start+1] != '*')
        return s_start<=s_end &&  (p[p_start] == '.' || p[p_start] == s[s_start]) && isMatch(s, s_start+1, s_end, p, p_start+1, p_end);
    //p[p_start+1] == '*'
    while(s_start<=s_end && (p[p_start] == s[s_start] || p[p_start] == '.')){
        if(isMatch(s, s_start, s_end, p, p_start+2, p_end)) return true;
        s_start++;
    }
    return isMatch(s, s_start, s_end, p, p_start+2, p_end);
//    return false;
}

bool isMatch(string s, string p){
    int s_len = s.length(), p_len = p.length();
    if(p_len == 0) return s_len == 0;
    return isMatch(s, 0, s_len-1, p, 0, p_len-1);
}

int main(){
    cout<<isMatch("aa","a")<<endl;
    cout<<isMatch("aa","aa")<<endl;
    cout<<isMatch("aaa","aa")<<endl;
    cout<<isMatch("aa", "a*")<<endl;
    cout<<isMatch("aa", ".*")<<endl;
    cout<<isMatch("ab", ".*")<<endl;
    cout<<isMatch("aab", "c*a*b")<<endl;
    cout<<isMatch("a", ".*..a*")<<endl;
    return 0;
}