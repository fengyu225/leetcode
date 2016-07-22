/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 */

#include "header.h"

/* dfs TLE
bool search(string& s, int curr, unordered_set<string>& wordDict){
    if(curr==s.length()) return true;
    bool res = false;
    for(int i=curr; i<s.length(); i++){
        string temp = s.substr(curr, i-curr+1);
        if(wordDict.find(temp) == wordDict.end()) continue;
        res |= search(s,i+1,wordDict);
    } 
    return res;
}

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int sz = s.length();
    if(sz == 0) return 0;
    return search(s,0,wordDict);
}
*/

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int sz = s.length();
    if(sz == 0) return false;
    vector<bool> arr(sz+1,false);
    arr[0] = true;
    for(int i=1; i<=sz; i++){
        for(int j=0; j<i; j++){
            arr[i] = arr[j] && (wordDict.find(s.substr(j, i-j)) != wordDict.end());
            if(arr[i]) break;
        } 
    }
    return arr[sz];
}

int main(){
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    string s("leetcodeleetleet");
    printf("%d\n", wordBreak(s,dict));
    return 0;
}
