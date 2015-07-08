/*
Implement wildcard pattern matching with support for '*'.

'*' Matches any sequence of characters (including the empty sequence).

The function prototype should be:
bool isMatch(const char *s, const char *p)

is true iff p match a substr of s

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
isMatch("tripadvisor", "ri*vi") → true 
*/

#include "header.h"

bool isMatch(string s, string p){
    p = "*"+p+"*";
    int curr_p = 0, curr_s = 0, last_p = -1, last_s = -1;
    int p_sz = p.length(), s_sz = s.length();
    while(curr_s < s_sz){
        cout<<curr_p<<" "<<curr_s<<endl;
        if(curr_p<p_sz && p[curr_p] == s[curr_s]){
            curr_p++;
            curr_s++;
        } 
        else if(curr_p<p_sz && p[curr_p] == '*'){
            last_p = curr_p++;
            last_s = curr_s;
        }
        else if(last_p<p_sz && last_p>=0){
            curr_s = ++last_s;
            curr_p = last_p+1;
        }
        else return false;
    }
    while(curr_p<p_sz && p[curr_p] == '*') curr_p++;
    return curr_p == p_sz;
}

int main(){
//    printf("%s\n", isMatch("aa","a")?"true":"false");
//    printf("%s\n", isMatch("aa","aa")?"true":"false");
//    printf("%s\n", isMatch("aaa","aa")?"true":"false");
//    printf("%s\n", isMatch("aa", "*")?"true":"false");
//    printf("%s\n", isMatch("aa", "a*")?"true":"false");
    printf("%s\n", isMatch("cdadadabe", "****a*")?"true":"false");
    printf("%s\n", isMatch("tripadvisor", "ri*vi")?"true":"false");
    printf("%s\n", isMatch("tripadvisor", "ri*vo")?"true":"false");
//    printf("%s\n", isMatch("aab", "c*a*b")?"true":"false");
    return 0;
}
