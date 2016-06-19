/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

#include "header.h"

bool is_vowel(char c){
    return 
        c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string reverseVowels(string s) {
    int sz = s.length();
    int l = 0, r=sz-1;
    while(l<r){
        if(!is_vowel(s[l])) l++;
        else if(!is_vowel(s[r])) r--;
        else swap(s[l++], s[r--]);
    }
    return s;
}

int main(){
    cout<<reverseVowels("leetcode")<<endl;
    return 0;
}
