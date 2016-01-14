/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

#include "header.h"

bool canPermutePalindrome(string s) {
    unordered_map<char,int> m;
    for(char c:s) m[c]++;
    int cnt = 0;
    for(auto p:m)
        if(p.second%2 == 1) cnt++;
    return cnt<=1;
}

int main(){
    cout<<canPermutePalindrome("code")<<endl;
    cout<<canPermutePalindrome("aab")<<endl;
    cout<<canPermutePalindrome("carerac")<<endl;
    return 0;
}