/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include "header.h"

vector<string> findRepeatedDnaSequences(string s){
    int sz = s.length();
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}