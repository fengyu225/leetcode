/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

#include "header.h"

//bool canPermutePalindrome(string s) {
//    int sz = s.length();
//    if(sz<2) return true;
//    int arr[256] = {0};
//    for(char c:s) arr[c]++;
//    int odd_count = 0;
//    for(int i=0; i<256; i++){
//        if(arr[i]%2 != 0) odd_count++;
//        if(odd_count>=2) return false;
//    }
//    return true;
//}

bool canPermutePalindrome(string s) {
    int arr[256] = {0};
    int odd = 0;
    for(char c:s) odd += (++arr[c])%2*2-1;
    return odd<2;
}

int main(){
    cout<<canPermutePalindrome("code")<<endl;
    cout<<canPermutePalindrome("aab")<<endl;
    cout<<canPermutePalindrome("carerac")<<endl;
    return 0;
}