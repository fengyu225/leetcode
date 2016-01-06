/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

#include "header.h"

int lengthOfLongestSubstringTwoDistinct(string s) {
    int sz = s.length();
    vector<int> has_found(256, 0);
    int l = 0, r = 0;
    int res = 0, distinct_cnt = 0;
    while(r<sz){
        has_found[s[r]]++;
        if(has_found[s[r]] == 1) distinct_cnt++;
        if(distinct_cnt <= 2) res = max(res, r-l+1);
        while(distinct_cnt>2){
            has_found[s[l]]--;
            if(has_found[s[l]] == 0) distinct_cnt--;
            l++;
        }
        r++;
    }
    return res;
}

int main(){
//    cout<<lengthOfLongestSubstringTwoDistinct("eceba")<<endl;
    cout<<lengthOfLongestSubstringTwoDistinct("abZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZYX")<<endl;
    return 0;
}