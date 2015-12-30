/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

#include "header.h"

string removeDuplicateLetters(string s) {
    // https://leetcode.com/discuss/73761/a-short-o-n-recursive-greedy-solution
    int sz = s.length();
    if(sz == 0) return "";
    vector<int> count(26, 0);
    for(int i=0; i<sz; i++) count[s[i]-'a']++;
    int pos = 0;
    for(int i=0; i<sz; i++){
        if(s[i]<s[pos]) pos = i;
        count[s[i]-'a']--;
        if(count[s[i]-'a'] == 0) break;
    }
    char temp = s[pos];
    s = s.substr(pos+1, sz-pos-1);
    s.erase(remove(s.begin(), s.end(), temp), s.end());
    return temp+removeDuplicateLetters(s);
}

int main(){
    cout<<removeDuplicateLetters("cbacdcbc")<<endl;
    return 0;
}