/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

#include "header.h"

int lengthOfLongestSubstringTwoDistinct(string s){
    int count = 0, l=0, res = 0, sz=s.length();
    int map[256] = {0};
    for(int i=0; i<sz; i++){
        if(map[s[i]] == 0) count++;
        map[s[i]]++;
        if(count<=2) res=max(res, i-l+1);
        else{
            while(count>2){
                if(map[s[l]] == 1) count--;
                map[s[l++]]--;
            }
        }
    }
    return res;
}

int main(){
    cout<<lengthOfLongestSubstringTwoDistinct("")<<endl;
    cout<<lengthOfLongestSubstringTwoDistinct("e")<<endl;
    cout<<lengthOfLongestSubstringTwoDistinct("eeeeeeeee")<<endl;
    cout<<lengthOfLongestSubstringTwoDistinct("abcdefg")<<endl;
    cout<<lengthOfLongestSubstringTwoDistinct("eceba")<<endl;
    return 0;
}