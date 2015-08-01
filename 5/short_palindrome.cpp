/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/
#include "header.h"

string shortestPalindrome(string s) {
    if(s.length()<2) return s;
    string orig = s;
    reverse(s.begin(), s.end());
    string ss = orig+"#"+s;
    vector<int> next(ss.length()+1, -1);
    int k = -1, curr = 0;
    next[0] = -1;
    while(curr<ss.length()){
        if(k == -1 || ss[curr]==ss[k]){
            k++;
            curr++;
            next[curr] = k;
        }
        else k = next[k];
    }
    int l = next[ss.length()];
    if(l == orig.length()) return orig;
    string pre = orig.substr(l, orig.length()-l);
    reverse(pre.begin(), pre.end());
    return pre+orig;
}

int main(){
    //cout<<shortestPalindrome("abbacd")<<endl;
    cout<<shortestPalindrome("abb")<<endl;
    return 0;
}