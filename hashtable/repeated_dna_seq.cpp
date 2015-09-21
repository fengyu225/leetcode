/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include "header.h"

//vector<string> findRepeatedDnaSequences(string s) {
//    //memory limit exceed
//    vector<string> res;
//    unordered_map<string,int> m;
//    int s_len = s.length();
//    for(int i=0; i+9<s_len; i++) m[s.substr(i, 10)]++;
//    for(auto x:m)
//        if(x.second>1) res.push_back(x.first);
//    return res;
//}

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    int s_len = s.length();
    if(s_len<=10) return res;
    unordered_set<string> res_str;
    unordered_set<int> set;
    unordered_map<int,int> m = {
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'T', 3}
    };
    unsigned long x = bitset<32>("00000000000011111111111111111111").to_ulong();
    int curr = 0, num=0;
    while(curr<10){
        num <<= 2;
        num |= m[s[curr++]];
    }
    set.insert(num);
    while(curr<s_len){
        num <<= 2;
        num |= m[s[curr++]];
        num &= x;
        if(set.find(num) != set.end()) res_str.insert(s.substr(curr-10, 10));
        else set.insert(num);
    }
    for(auto i:res_str) res.push_back(i);
    return res;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}