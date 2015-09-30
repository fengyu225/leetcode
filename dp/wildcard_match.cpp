/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include "header.h"

bool isMatch(string s, string p){
    int s_len = s.length(), p_len = p.length();
    int s_curr = 0, p_curr = 0;
    int s_last = -1, p_last = -1;
    while(s_curr<s_len){
        if(p_curr<p_len && (s[s_curr] == p[p_curr] || p[p_curr] == '?')){
            s_curr++;
            p_curr++;
        }
        else if(p_curr<p_len && p[p_curr] == '*'){
            p_last = p_curr++;
            s_last = s_curr;
        }
        else if(p_last>=0){
            p_curr = p_last+1;
            s_curr = ++s_last; 
        }
        else return false;
    }
    return true;
}

int main(){
//    printf("%s\n", isMatch("aa","a")?"true":"false");
//    printf("%s\n", isMatch("aa","aa")?"true":"false");
//    printf("%s\n", isMatch("aaa","aa")?"true":"false");
//    printf("%s\n", isMatch("aa", "*")?"true":"false");
//    printf("%s\n", isMatch("aa", "a*")?"true":"false");
    printf("%s\n", isMatch("cdadadabe", "?****a*?")?"true":"false");
//    printf("%s\n", isMatch("aab", "c*a*b")?"true":"false");
    return 0;
}
