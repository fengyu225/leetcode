/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include "header.h"

vector<string> anagrams(vector<string>& strs) {
    int sz = strs.size();
    if(sz < 2) return strs;
    unordered_map<string, vector<int> > map;
    for(int i=0; i<sz; i++){
        string k = strs[i];
        sort(k.begin(), k.end());
        map[k].push_back(i);
    }
    vector<string> res;
    for(auto i=map.begin(); i!=map.end(); i++){
        if(i->second.size()>1){
            for(int j=0; j<i->second.size(); j++)
                res.push_back(strs[i->second[j]]);
        }
    }
    return res;
}

int main(){
    string s0("");
//    string s0("tea");
//    string s1("and");
//    string s2("ate");
//    string s3("eat");
//    string s4("den");
    vector<string> strs;
    strs.push_back(s0);
//    strs.push_back(s1);
//    strs.push_back(s2);
//    strs.push_back(s3);
//    strs.push_back(s4);
    vector<string> res = anagrams(strs);
    for(int i=0; i<res.size(); i++)
        printf("%s ", res[i].c_str());
    printf("\n");
    return 0;
}
