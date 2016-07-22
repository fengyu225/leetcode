/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

#include "header.h"

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int res = 0, curr_distinct = 0, sz = s.length(), l = 0;
    vector<int> m(256, 0);
    for(int r=0; r<sz; r++){
        m[s[r]]++;
        if(m[s[r]] == 1) curr_distinct++;
        if(curr_distinct<=k) res = max(res, r-l+1);
        else if(curr_distinct>k){
            while(l<=r){
                m[s[l++]]--;
                if(m[s[l-1]] == 0){
                    curr_distinct--;
                    break;
                }
            }
        }
    }
    return res;
}

int main(){
    cout<<lengthOfLongestSubstringKDistinct("eceba", 20)<<endl;
    return 0;
}
