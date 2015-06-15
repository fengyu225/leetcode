/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

#include "header.h"

int lengthOfLongestSubstringTwoDistinct(string s){
    int sz = s.length();
    if(sz <= 2) return sz;
    int count = 1;
    int l=0, r=1;
    int res = 1;
    vector<int> arr(256,0);
    arr[s[l]]=1;
    while(r<sz){
        if(arr[s[r]]>0 || count<2){
            res=max(res,r-l+1);
            arr[s[r]]++;
            if(count<2) count++;
        }
        else if(count == 2){
            count++;
            while(l<=r && arr[s[l]]>1) l++;
            if(l<=r){
                arr[s[l]]=0;
                l++;
                count--;
            }
        }
        r++;
    }
    return res;
}

int main(){
    cout<<lengthOfLongestSubstringTwoDistinct("eceba")<<endl;
    return 0;
}