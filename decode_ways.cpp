/*
  A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/

#include "header.h"

int numDecodings(string s){
    int s_len = s.length();
    if(s_len==0) return s_len;
    vector<int> arr(s_len, 0);
    if(s[0] == '0') return 0;
    arr[0] = 1;
    for(int i=1; i<s_len; i++){
        int temp = 0;
        if(i-1>=0 && (s[i-1] == '1' || s[i-1] == '2' && s[i]<='6' && s[i]>='0'))
            temp += i-2>=0?arr[i-2]:1;
        if(s[i]!='0')
            temp += arr[i-1];
        arr[i] = temp;
    }
    return arr[s_len-1];
}

int main(){
    string s0("11");
    printf("%d\n", numDecodings(s0));
    string s1("00");
    printf("%d\n", numDecodings(s1));
    string s2("10");
    printf("%d\n", numDecodings(s2));
    string s3("27");
    printf("%d\n", numDecodings(s3));
    string s4("01");
    printf("%d\n", numDecodings(s4));
    return 0;
}
