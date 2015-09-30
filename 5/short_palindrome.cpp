/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/
#include "header.h"

string shortestPalindrome(string s) {
    string temp = s;
    reverse(s.begin(), s.end());
    s = temp+"#"+s;
    int s_len = s.length();
    vector<int> next(s_len+1, -1);
    int curr = 0, k = -1;
    while(curr<s_len){
        if(k == -1 || s[curr] == s[k]) next[++curr] = ++k;
        else{
            k = next[k];
        }
    }
    int l = next[s_len];
    if(l == temp.length()) return temp;
    string pre = temp.substr(l, temp.length()-l);
    reverse(pre.begin(), pre.end());
    return pre+temp;
}

int main(){
    //cout<<shortestPalindrome("abbacd")<<endl;
    cout<<shortestPalindrome("abb")<<endl;
    return 0;
}