/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

#include "header.h"

void reverse(string& s, int l, int r){
    for(;l<r;l++,r--){
        char c = s[l];
        s[l] = s[r];
        s[r] = c;
    }
}

void reverseWords(string& s) {
    int sz = s.length();
    if(sz==0 ) return;
    int start = 0, end = 0, curr = 1;
    reverse(s, 0, sz-1);
    while(curr<sz){
        if(s[end] == ' '){
            if(s[curr] == ' ') curr++;
            else{
                s[++end] = s[curr++];
                start = end;
            }
        }
        else{
            if(s[curr] == ' '){
                reverse(s, start, end);
                s[++end] = s[curr++];
                start = end;
            }
            else s[++end] = s[curr++];
        }
    }
    if(s[end] != ' ') reverse(s, start, end);
    start = s[0] == ' '?1:0;
    end = s[end] == ' ' && end>0?end-1:end;
    s=s.substr(start, end-start+1);
}

int main(){
    //string s = "        hello         ,           world           ";
    string s = "        ";
    reverseWords(s);
    cout<<"|"<<s<<"|"<<endl;
    return 0;
}