/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 */

#include "header.h"

bool wordBreak(string s, unordered_set<string>& wordDict) {
    return false;
}

int main(){
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    string s("leetcodeleetleet");
    printf("%d\n", wordBreak(s,dict));
    return 0;
}
