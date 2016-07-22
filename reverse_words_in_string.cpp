/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
*/

#include "header.h"

void reverse_str(string& s, int l, int r){
    for(;l<r;l++,r--){
        char c = s[l];
        s[l] = s[r];
        s[r] = c;
    }
}

void reverseWords(string &s) {
    int sz = s.length();
    reverse_str(s, 0, sz-1);
    int start = 0, curr = 0;
    while(curr<sz){
        if(s[curr] == ' '){
            reverse_str(s, start, curr-1);
            curr++;
            start = curr;
        }
        else curr++;
    }
    reverse_str(s, start, curr-1);
}

int main(){
    string s = "the sky is blue";
    reverseWords(s);
    cout<<"|"<<s<<"|"<<endl;
    return 0;
}