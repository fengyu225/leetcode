/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

#include "header.h"

int numDistinct(string s, string t){
    int s_sz = s.length(), t_sz = t.length();
    if(s_sz == 0) return 0;
    if(t_sz>s_sz) return 0;
    int arr[s_sz+1][t_sz+1];
    memset(arr,0,sizeof(arr));
    arr[0][0] = 1;
    for(int i=1; i<=s_sz; i++){
        for(int j=0; j<=t_sz; j++){
            if(j == 0) arr[i][0] = 1;
            else{
                if(s[i-1] == t[j-1]) arr[i][j]+=arr[i-1][j-1];
                arr[i][j] += arr[i-1][j];
            }
        }
    }
    return arr[s_sz][t_sz];
}

int main(){
    string S("rabbbit");
    string T("rabbit");
//    string S("b");
//    string T("a");
    printf("%d\n", numDistinct(S,T));
    return 0;
}
