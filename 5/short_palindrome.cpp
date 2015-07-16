/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/
#include "header.h"

string shortestPalindrome(string s) {
    if(s.length()<2) return s;
    string ss = s+"#";
    string orig = s;
    reverse(s.begin(), s.end());
    ss += s;
    int sz = ss.length();
    vector<int> next(sz+1, -1);
    int k=-1, j=0;
    next[0] = -1;
    while(j<sz){
        if(k == -1 || ss[j] == ss[k]){
            k++;
            j++;
            next[j] = k;
        } 
        else k = next[k];
    }
    string x = ss.substr(next[sz], orig.length()-next[sz]);
    reverse(x.begin(), x.end());
    return x+orig;
}

int main(){
    cout<<shortestPalindrome("abbacd")<<endl;
    return 0;
}