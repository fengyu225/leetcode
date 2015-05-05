/*
 *  Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 *  A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 *  Here is an example:
 *  S = "rabbbit", T = "rabbit"
 *
 *  Return 3. 
 *
 *  (how many subseq of S that equals to T)
 */
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

int numDistinct(string s, string t){
    if(s.size()<t.size())
        return 0;
    int m[t.size()+1][s.size()+1];
    for(int i=0; i<=s.size(); i++) m[0][i] = 1;
    for(int i=1; i<=t.size(); i++) m[i][0] = 0;
    for(int i=1; i<=t.size(); i++)
        for(int j=1; j<=s.size(); j++){
            if(s[j-1] == t[i-1])
                m[i][j] = m[i-1][j-1]+m[i][j-1];
            else
                m[i][j] = m[i][j-1];
        }
    return m[t.size()][s.size()];
}

int main(){
    //string S("rabbbit");
    //string T("rabbit");
    string S("ccc");
    string T("c");
    printf("%d\n", numDistinct(S,T));
    return 0;
}
