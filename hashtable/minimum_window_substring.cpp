/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include "header.h"

string minWindow(string s, string t) {
    int s_len = s.length(), t_len = t.length();
    if(s_len<t_len) return "";
    int need_to_find[256] = {0};
    int has_found[256] = {0};
    int l = 0, r = 0;
    int count = 0, res_len = s_len+1, res_start = -1;
    for(int i=0; i<t_len; i++) need_to_find[t[i]]++;
    for(;r<s_len; r++){
        if(need_to_find[s[r]] == 0) continue;
        has_found[s[r]]++;
        if(has_found[s[r]]<=need_to_find[s[r]]) count++;
        if(count == t_len){
            while(need_to_find[s[l]] == 0 || has_found[s[l]]>need_to_find[s[l]]) 
                has_found[s[l++]]--;
            if(r-l+1<res_len){
                res_len = r-l+1;
                res_start = l;
            }
            has_found[s[l++]]--;
            count--;
        }
    }
    if(res_start == -1) return "";
    return s.substr(res_start, res_len);
}

int main(){
    string s("ADOBECODEBANC");
    string t("ABC");
//    string s("cabwefgewcwaefgcf");
//    string t("cae");
    //string r = minWindow(s,t);
    string r = minWindow("a","aa");
    printf("%s\n", r.c_str());
}
