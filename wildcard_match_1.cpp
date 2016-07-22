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

bool isMatch(char* s, char* p){
    int s_sz = strlen(s), p_sz = strlen(p);
    if(p_sz == 0) return s_sz == 0;
    for(int i=0; i<s_sz; i++){
        int curr_s = i, curr_p = 0;
        int last_s = -1, last_p = -1;
        while(curr_s<s_sz){
            if(curr_p == p_sz) return true;
            if(s[curr_s] == p[curr_p]){
                curr_s++;
                curr_p++;
            }
            else if(p[curr_p] == '*'){
                last_s = curr_s;
                last_p = curr_p++;
            }
            else if(last_p>=0){
                curr_s = ++last_s;
                curr_p = last_p+1;
            }
            else break;
        }
        if(curr_s == s_sz){
            while(curr_p<p_sz && p[curr_p] == '*') curr_p++;
            if(curr_p == p_sz) return true;
        }
    }
    return false;
}

int main(){
//    printf("%s\n", isMatch("aa","a")?"true":"false");
//    printf("%s\n", isMatch("aa","aa")?"true":"false");
//    printf("%s\n", isMatch("aaa","aa")?"true":"false");
//    printf("%s\n", isMatch("aa", "*")?"true":"false");
//    printf("%s\n", isMatch("aa", "a*")?"true":"false");
    char s[] = "TripAdvisor";
    //char p[] = "ri*pAdt***********"; 
    char p[] = "ri*pAd***********"; 
    cout<<isMatch(s,p)<<endl;
//    printf("%s\n", isMatch("aab", "c*a*b")?"true":"false");
    return 0;
}
