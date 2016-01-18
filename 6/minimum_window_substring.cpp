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
    int sz = s.length();
    if(sz == 0) return "";
    vector<int> need_to_find(256, 0);
    vector<int> has_found(256, 0);
    for(char c:t) need_to_find[c]++;
    int count = 0;
    int l = 0, r = 0, t_sz = t.length();
    int res_start, res_len = sz+1;
    while(r<sz){
        has_found[s[r]]++;
        if(has_found[s[r]]<=need_to_find[s[r]]) count++;
        r++;
        while(count == t_sz){
            if(res_len>r-l){
                res_len = r-l;
                res_start = l;
            }
            has_found[s[l]]--;
            if(has_found[s[l]]<need_to_find[s[l]]) count--;
            l++;
        }
    }
    if(res_len == sz+1) return "";
    return s.substr(res_start, res_len);
}

int main(){
    string s("ADOBECODEBANC");
    string t("ABC");
//    string s("cabwefgewcwaefgcf");
//    string t("cae");
    string r = minWindow(s,t);
    printf("%s\n", r.c_str());
}
