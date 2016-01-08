/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include "header.h"

unordered_map<char,int> m = {
    {'A',0},
    {'C',1},
    {'G',2},
    {'T',3}
};

int str_2_int(string s){
    int res = 0;
    for(int i=0;i<s.length();i++){
        res |= m[s[i]];
        res <<= 2;
    }
    res >>= 2;
    return res;
}

vector<string> findRepeatedDnaSequences(string s){
    int sz = s.length();
    unordered_set<int> st;
    if(sz<10) return vector<string>();
    int curr = str_2_int(s.substr(0,10));
    st.insert(curr);
    unordered_set<int> more_than_twice;
    vector<string> res;
    for(int i=1; i<=sz-10; i++){
        curr <<= 2;
        curr &= (1<<20)-1;
        curr |= m[s[i+9]];
        if(st.find(curr) != st.end()){
            if(more_than_twice.find(curr) == more_than_twice.end()){
                res.push_back(s.substr(i,10));
                more_than_twice.insert(curr);
            }
        }
        else st.insert(curr);
    }
    return res;
}

int main(){
//    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s = "AAAAAAAAAAAA";
    vector<string> res = findRepeatedDnaSequences(s);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}