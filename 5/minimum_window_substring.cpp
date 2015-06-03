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

string minWindow(string s, string t){
    int need_to_find[256];
    int has_found[256];
    memset(has_found, 0, sizeof(has_found));
    memset(need_to_find, 0, sizeof(need_to_find));
    int sz = s.length(), l=0, r=0, count=0;
    for(int i=0; i<t.length(); i++) need_to_find[t[i]]++; 
    int min_start = -1, min_len = INT_MAX;
    for(;r<=sz;r++){
        if(need_to_find[s[r]] == 0) continue;
        has_found[s[r]]++;
        if(has_found[s[r]]<=need_to_find[s[r]]) count++;
        if(count == t.length()){
            while(need_to_find[s[l]] == 0 || has_found[s[l]]>need_to_find[s[l]]){
                if(has_found[s[l]]>need_to_find[s[l]]) has_found[s[l]]--;
                l++;
            }
            if(r-l+1<min_len){
                min_len = r-l+1;
                min_start = l;
            }
        }
    }
    if(min_start == -1) return "";
    return s.substr(min_start, min_len);
}

int main(){
    string s("ADOBECODEBANC");
    string t("ABC");
//    string s("cabwefgewcwaefgcf");
//    string t("cae");
    string r = minWindow(s,t);
    printf("%s\n", r.c_str());
}
