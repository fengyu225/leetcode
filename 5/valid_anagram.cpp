/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

#include "header.h"

bool isAnagram(string s, string t) {
    int s_sz = s.length();
    int t_sz = t.length();
    if(s_sz != t_sz) return false;
    vector<int> arr(26, 0);
    for(auto c:s) arr[c-'a']++;
    for(auto c:t){
        if(arr[c-'a'] == 0) return false;
        arr[c-'a']--;
    }
    return true;
}

int main(){
    cout<<isAnagram("anagram", "nagaram")<<endl;
    cout<<isAnagram("rat", "car")<<endl;
    return 0;
}