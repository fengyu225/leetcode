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
    vector<string> res;
    if(s.length()<=10) return res; 
    unordered_set<int> set;
    unordered_set<string> res_set;
    unordered_map<int,int> m;
    m['A'] = 0;
    m['C'] = 1;
    m['G'] = 2;
    m['T'] = 3;
    int num = 0;
    int x = 0;
    for(int i=0; i<20; i++) x |= (1<<i);
    int curr = 0;
    while(curr<10){
        num <<= 2;
        num |= m[s[curr++]];
    }
    set.insert(num);
    while(curr<s.length()){
        num <<= 2;
        num |= m[s[curr++]];
        num &= x;
        if(set.find(num) != set.end()) res_set.insert(s.substr(curr-10, 10));
        else set.insert(num);
    }
    for(auto i = res_set.begin(); i!=res_set.end(); i++) res.push_back(*i);
    return res;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}