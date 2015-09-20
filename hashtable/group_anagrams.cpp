/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
Update (2015-08-09):
The signature of the function had been updated to return list<list<string>> instead of list<string>, as suggested here. If you still see your function signature return a list<string>, please click the reload button  to reset your code definition.
*/

#include "header.h"

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    unordered_map<string, vector<string> > m;
    for(string s:strs){
        string temp = s;
        sort(temp.begin(), temp.end());
        if(m.find(temp) == m.end()) m[temp] = vector<string>();
        m[temp].push_back(s);
    }
    for(auto i:m){
        sort(i.second.begin(), i.second.end());
        res.push_back(i.second);
    }
    return res;
}

int main(){
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    vector<vector<string> > res = groupAnagrams(strs);
    print_2d_vector<string>(res);
    return 0;
}