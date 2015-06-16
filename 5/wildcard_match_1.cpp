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
    int s_curr = 0, p_curr = 0;
    int last_s = -1; last_p = -1;
    while(s_curr<s.length()){
        if(p[p_curr] == '?' || s[s_curr] == p[p_curr]){
            s_curr++;
            p_curr++;
            continue;
        }
        if(p[p_curr] == '*'){
            last_p = p_curr++;
            last_s = s_curr;
            continue;
        }
        if(last_p>=0){
            p_curr = last_p+1;
            s_curr = ++last_s;
        }
        else return false;
    } 
    while(p[p_curr] == '*') p_curr++;
    return p_curr == p.length();
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
