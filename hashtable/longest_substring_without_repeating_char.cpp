/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include "header.h"

int lengthOfLongestSubstring(string s) {
    int sz = s.length();
    if(sz<2) return sz;
    bool arr[256];
    memset(arr, 0, sizeof(arr));
    int res = 1;
    int l=0, r=0;
    for(; r<sz; r++){
        if(!arr[s[r]]) arr[s[r]] = true;
        else{
            res = max(res, r-l);
            while(l<r && s[l] != s[r]){
                arr[s[l++]] = false;
            }
            l++;
        }
    }
    res = max(res, r-l);
    return res;
}

int main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); //abc
    printf("%d\n", lengthOfLongestSubstring("bbbbb")); //b
    return 0;
}
