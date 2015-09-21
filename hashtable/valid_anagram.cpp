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
    int s_len = s.length(), t_len = t.length();
    if(s_len != t_len) return false;
    int arr[26] = {0};
    for(int i=0; i<s_len; i++) arr[s[i]-'a']++;
    for(int i=0; i<t_len; i++){
        if(arr[t[i]-'a'] == 0) return false;
        arr[t[i]-'a']--;
    }
    return true;
}

int main(){
    cout<<isAnagram("anagram", "nagaram")<<endl;
    cout<<isAnagram("rat", "car")<<endl;
    return 0;
}