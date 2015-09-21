/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include "header.h"

vector<string> findRepeatedDnaSequences(string s) {
    //memory limit exceed
    vector<string> res;
    unordered_map<string,int> m;
    int s_len = s.length();
    for(int i=0; i+9<s_len; i++) m[s.substr(i, 10)]++;
    for(auto x:m)
        if(x.second>1) res.push_back(x.first);
    return res;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}