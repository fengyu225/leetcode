/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

#include "header.h"

int numDistinct(string s, string t){

}

int main(){
    string S("rabbbit");
    string T("rabbit");
//    string S("b");
//    string T("a");
    printf("%d\n", numDistinct(S,T));
    return 0;
}
