/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

#include "header.h"

int lengthOfLongestSubstringTwoDistinct(string s) {
    //two pointers
    int s_len = s.length();    
    if(s_len < 2) return s_len;
    int has_found[256] = {0};
    int l = 0, r = 0, res=0, count = 0;
    for(;r<s_len;r++){
        has_found[s[r]]++;
        if(has_found[s[r]] == 1) count++;
        if(count <= 2) res = max(res, r-l+1);
        if(count == 3){
            while(l<r && count == 3){
                has_found[s[l]]--;
                if(has_found[s[l]] == 0) count--;
                l++;
            }
        }
    }
    return res;
}

int main(){
    cout<<lengthOfLongestSubstringTwoDistinct("eceba")<<endl;
    return 0;
}