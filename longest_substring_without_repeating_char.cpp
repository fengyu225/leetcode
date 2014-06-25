#include "header.h"

int lengthOfLongestSubstring(string s) {
    if(s.size() <= 1) return s.size();
    int result = 0;
    int l=0,r=0,s_size=s.size();
    unordered_set<char> st; 
    while(r<s_size){
        if(st.find(s[r]) == st.end()){
            st.insert(s[r]);
            result = result<r-l+1?r-l+1:result;
            r++;
            continue;
        }
        do{
            st.erase(s[l]);
        }while(s[l++]!=s[r]);
    }
    return result<r-l?r-l:result;
}

int main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); //abc
    printf("%d\n", lengthOfLongestSubstring("bbbbb")); //b
    return 0;
}
