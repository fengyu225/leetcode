/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
For C programmers: Try to solve it in-place in O(1) space.
*/

#include "header.h"

void reverse(string& s, int l, int r){
    while(l<r){
        char c = s[l];
        s[l] = s[r];
        s[r] = c;
        l++;
        r--;
    }
}

void reverseWords(string& s) {
    int sz = s.length();
    if(sz==0 ) return;
    reverse(s,0,sz-1);
    int l=0, r=1;
    while(r<sz){
        if(s[r] == ' '){
            if(s[l] == ' ') r++;
            else{
                reverse(s,l,r-1);
                l = r;
                r++;
            }
        }
        else{
            if(s[l] == ' ') l=r;
            r++;
        }
    }
    int curr=-1;
    l = 0;
    while(l<sz && s[l]==' ') l++;
    if(l != 0)
        while(l<sz) s[++curr]=s[l++];
    r=curr==-1?sz-1:curr;
    while(r>=0 && s[r]==' ') r--;
    s=s.substr(0,r+1);
}   

int main(){
//    string s("   the sky is blue ");
    string s("a");
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}
