#include "header.h"

int lengthOfLongestSubstring(string s) {
    int res = 0;
    if(s.size()<2) return s.size();
    int sz = s.size();
    int l = 0, r = 0;
    unordered_set<char> set;
    while(r<sz){
        if(set.find(s[r]) == set.end()){
            set.insert(s[r]);
            res = std::max(res,r-l+1);
            r++;
            continue;
        }
        do{
            set.erase(s[l]);
        }while(s[l++] != s[r]);
    }
    return res;
}

int main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); //abc
    printf("%d\n", lengthOfLongestSubstring("bbbbb")); //b
    return 0;
}
