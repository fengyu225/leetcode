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
    int l = 0, r = 0, cnt = 0;
    vector<int> has_found(256, 0);
    vector<int> need_to_find(256, 0);
    int res_start = -1, res_len = s_len+1;
    for(char c:t) need_to_find[c]++;
    for(;r<s_len;r++){
        char c = s[r];
        if(need_to_find[c] == 0) continue;
        has_found[c]++;
        if(has_found[c]<=need_to_find[c]) cnt++;
        if(cnt == t_len){
            while(l<=r && cnt == t_len){
                if(r-l+1<res_len){
                    res_len = r-l+1;
                    res_start = l;
                }
                c = s[l];
                l++;
                if(need_to_find[c] == 0) continue;
                has_found[c]--;
                if(has_found[c]<need_to_find[c]) cnt--;
            }
        }
    }
    if(res_start == -1) return "";
    else return s.substr(res_start, res_len);
}

int main(){
    string s("ADOBECODEBANC");
    string t("ABC");
//    string s("cabwefgewcwaefgcf");
//    string t("cae");
    string r = minWindow(s,t);
    printf("%s\n", r.c_str());
}
