/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

#include "header.h"

bool canPermutePalindrome(string s) {
    int s_len = s.length(), odd = 0;
    int arr[256] = {0};
    for(char c:s) arr[c]++;
    for(int i=0; i<256; i++) if(arr[i]&1) odd++;
    return odd == 0 || odd == 1;
}

int main(){
    cout<<canPermutePalindrome("code")<<endl;
    cout<<canPermutePalindrome("aab")<<endl;
    cout<<canPermutePalindrome("carerac")<<endl;
    return 0;
}