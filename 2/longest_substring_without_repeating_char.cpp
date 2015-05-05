#include "header.h"

int lengthOfLongestSubstring(string s) {
    if(s.size()<2) return s.size();
    int arr[256] = {0};
    int l=0,r=0;
    int max_len=-1;
    while(r<s.size()){
        if(arr[s[r]] == 0){
            max_len = std::max(max_len,r-l+1);
            arr[s[r]]++;
            r++;
            continue;
        }
        do{
            arr[s[l]]--;
            l++;
        }while(l<r && s[l] != s[r]);
    }
    return max_len;
}

int main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); //abc
    printf("%d\n", lengthOfLongestSubstring("bbbbb")); //b
    return 0;
}
