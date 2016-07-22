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
    int s_sz = s.length(), p_sz = p.length();
    int curr_s = 0, curr_p = 0, last_p=-1, last_s=-1;
    while(curr_s<s_sz){
        if((curr_p<p_sz && s[curr_s]==p[curr_p])||(curr_p<p_sz && p[curr_p]=='?')){
            curr_s++;
            curr_p++;
        }
        else if(curr_p<p_sz && p[curr_p]=='*'){
            last_p = curr_p++;
            last_s = curr_s;
        }
        else if(last_p>=0){
            curr_p = last_p+1;
            curr_s = ++last_s;
        }
        else return false;
    }
    while(curr_p<p_sz && p[curr_p]=='*') curr_p++;
    return curr_p == p_sz;
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
