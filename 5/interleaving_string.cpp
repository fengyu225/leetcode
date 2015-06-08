/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include "header.h"

bool isInterleave(string s1, string s2, string s3){

}

int main(){
//    string s1("aacaac");
//    string s2("aacaaeaac");
//    string s3("aacaaeaaeaacaac");
    string s1("c");
    string s2("");
    string s3("a");
    string s4("aadbbbaccc");
    printf("%s\n", isInterleave(s1,s2,s3)?"true":"false");
    printf("%s\n", isInterleave(s1,s2,s4)?"true":"false");
    return 0;
}
