#include "header.h"

string minWindow(string s, string t){
    int need_to_find[256];
    int has_found[256];
    memset(need_to_find,0,sizeof(need_to_find));
    memset(has_found,0,sizeof(has_found));
    int count = 0;
    int min_len = INT_MAX,min_start = -1;
    for(int i=0; i<t.size(); i++)
        need_to_find[t[i]]++;
    int l=0,r=0;
    for(;r<s.size();r++){
        if(need_to_find[s[r]] == 0) continue;
        has_found[s[r]]++;
        if(has_found[s[r]]<=need_to_find[s[r]])
            count++;
        if(count == t.size()){
            while(need_to_find[s[l]] == 0 || has_found[s[l]]>need_to_find[s[l]]){
                if(has_found[s[l]]>need_to_find[s[l]])
                    has_found[s[l]]--;
                l++;
            }
            if(r-l+1<min_len){
                min_len = r-l+1;
                min_start = l;
            }
        }
    }
    if(min_len == INT_MIN)
        return string("");
    return s.substr(min_start,min_len);
}

int main(){
//    string s("ADOBECODEBANC");
//    string t("ABC");
    string s("cabwefgewcwaefgcf");
    string t("cae");
    string r = minWindow(s,t);
    printf("%s\n", r.c_str());
}
