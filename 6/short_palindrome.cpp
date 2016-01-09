/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/
#include "header.h"

string shortestPalindrome(string s) {
    int sz = s.length();
    if(sz<2) return s;
    string temp = s, orig_s = s;
    reverse(s.begin(), s.end());
    temp += "#"+s;
    sz = temp.length();
    vector<int> arr(sz+1, -1);
    int k = -1; 
    for(int i=1; i<sz+1; i++){
        while(k != -1 && temp[k] != temp[i-1]) k=arr[k];
        arr[i] = ++k;
    }
    int m = arr[sz];
    sz = orig_s.length();
    temp = orig_s.substr(m, sz-m);
    reverse(temp.begin(), temp.end());
    return temp+orig_s;
}

int main(){
    //cout<<shortestPalindrome("abbacd")<<endl;
    //cout<<shortestPalindrome("abb")<<endl;
    cout<<shortestPalindrome("aacecaaa")<<endl;
    //cout<<shortestPalindrome("ississipi")<<endl;
    return 0;
}