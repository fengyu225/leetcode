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
    int sz = s.length();
    if(sz == 0) return 0;
    vector<int> arr(sz+1, 0);
    arr[0] = 1;
    arr[1] = s[0]=='0'?0:1;
    for(int i=2; i<=sz; i++){
        int a = s[i-1]=='0'?0:arr[i-1];
        int temp = stoi(s.substr(i-2, 2));
        if(temp>=1 && temp<=26 && s[i-2]!='0') a+=arr[i-2];
        arr[i] = a;
    }
    return arr[sz];
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
