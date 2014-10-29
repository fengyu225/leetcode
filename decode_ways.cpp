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

bool valid(string s, int i, int j){
    if(j == 1)
        return s[i]-'0'>=1 && s[i]-'0'<=26;
    if(j == 2)
        return (s[i] == '1' || (s[i] == '2' && s[i+1]-'0'<=6));
}

int numDecodings(string s){
    int sz = s.size();
    if(sz == 0 || sz==1 && s[0] == '0') return 0;
    if(sz == 1 && s[0]-'0'>=1 && s[0]-'0'<=26) return 1;
    int arr[sz];
    memset(arr,0,sizeof(arr));
    arr[0] = valid(s,0,1)?1:0;
    arr[1] = (valid(s,0,1) && valid(s,1,1)?1:0) + (valid(s,0,2)?1:0);
    for(int i=2; i<sz; i++){
        if(valid(s,i,1))
            arr[i] += arr[i-1];
        if(valid(s,i-1,2))
            arr[i] += arr[i-2];
    }
    return arr[sz-1];
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
    return 0;
}
