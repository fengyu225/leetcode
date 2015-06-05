/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include "header.h"

bool isScramble(string s1, string s2){
    int s1_len = s1.length(), s2_len = s2.length();
    if(s1_len != s2_len) return false;
    if(s1_len == 1) return s1 == s2;
    bool arr[s1_len][s2_len][s1_len+1];
    memset(arr, 0, sizeof(arr));
    for(int len=1; len<=s1_len; len++){
        for(int i=0; i+len<=s1_len; i++){
            for(int j=0; j+len<=s2_len; j++){
                if(len == 1) arr[i][j][1] = s1[i]==s2[j]?true:false;
                else{
                    for(int p=1;p<len;p++)
                        arr[i][j][len] |= (
                                (arr[i][j][p] && arr[i+p][j+p][len-p]) ||
                                (arr[i][len+j-p][p] && arr[i+p][j][len-p])
                                );
                }
            }
        }
    }
    for(int len=1; len<=s1_len; len++){
        cout<<"==================== "<<len<<endl;
        for(int i=0; i<s1_len; i++){
            for(int j=0; j<s1_len; j++)
                cout<<arr[i][j][len]<<" ";
            cout<<endl;
        }
    }
    return arr[0][0][s1_len];
}

int main(){
    printf("%d\n", isScramble("great", "rgtae"));
//      printf("%d\n", isScramble("eat", "tae"));
//    printf("%d\n", isScramble("great", "great"));
//    printf("%d\n", isScramble("abc", "bca"));
//    printf("%d\n", isScramble("abc", "cab"));
//    printf("%d\n", isScramble("abcd", "bcad"));
//    printf("%d\n", isScramble("abcd", "cabd"));
    return 0;
}
