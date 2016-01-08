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

void reverse(string& s, int i, int j){
    for(;i<j;swap(s[i++], s[j--]));
}

void reverseWords(string &s) {
    int sz = s.length();
    reverse(s, 0, sz-1);
    int begin = 0, curr = 0;
    while(begin<sz){
        if(curr == sz || s[curr] == ' '){
            reverse(s, begin, curr-1);
            begin = curr+1;
        }
        curr++;
    }
}

int main(){
    string s = "the sky is blue";
    reverseWords(s);
    cout<<"|"<<s<<"|"<<endl;
    return 0;
}