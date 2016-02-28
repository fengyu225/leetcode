/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include "header.h"

//vector<string> findRepeatedDnaSequences(string s){
//    vector<string> res;
//    if(s.length()<=10) return res; 
//    unordered_set<int> set;
//    unordered_set<string> res_set;
//    unordered_map<int,int> m;
//    m['A'] = 0;
//    m['C'] = 1;
//    m['G'] = 2;
//    m['T'] = 3;
//    int num = 0;
//    int x = 0;
//    for(int i=0; i<20; i++) x |= (1<<i);
//    int curr = 0;
//    while(curr<10){
//        num <<= 2;
//        num |= m[s[curr++]];
//    }
//    set.insert(num);
//    while(curr<s.length()){
//        num <<= 2;
//        num |= m[s[curr++]];
//        num &= x;
//        if(set.find(num) != set.end()) res_set.insert(s.substr(curr-10, 10));
//        else set.insert(num);
//    }
//    for(auto i = res_set.begin(); i!=res_set.end(); i++) res.push_back(*i);
//    return res;
//}

unordered_map<char,int> char_i = {
    {'A',0},
    {'C',1},
    {'G',2},
    {'T',3}
};

int str_2_int(string s){
    int res = 0;
    for(int i=0; i<s.length(); i++){
        res |= char_i[s[i]];
        res <<= 2;
    }
    res >>=2;
    return res;
}

vector<string> findRepeatedDnaSequences(string s) {
    int sz = s.length();
    vector<string> res;
    if(sz<=10) return res;
    unordered_map<int,int> m;
    unordered_set<string> st;
    int temp = str_2_int(s.substr(0,10)); 
    m[temp] = 1;
    for(int i=1; i+10<sz+1; i++){
        temp <<= 2;
        temp &= ((1<<20)-1);
        temp |= char_i[s[i+9]];
        m[temp]++;
        if(m[temp]>1) st.insert(s.substr(i,10));
    }
    for(string temp:st) res.push_back(temp);
    return res;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}