/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

#include "header.h"

void build_edges(string& a, string& b, unordered_map<char, unordered_set<char> >& edges){
    int a_l = a.length(), b_l = b.length();
    int l = min(a_l, b_l);
    for(int i=0; i<l; i++){
        if(a[i] == b[i]) continue;
        edges[a[i]].insert(b[i]);
        break;
    }
}

bool search(unordered_map<char,unordered_set<char> >& edges, char curr, vector<int>& visited, string& res){
    for(char n:edges[curr]){
        if(visited[n-'a'] == 1) return false;
        if(visited[n-'a'] == 2) continue;
        visited[n-'a'] = 1;
        bool temp = search(edges, n, visited, res);
        if(!temp) return false;
    }
    visited[curr-'a']=2;
    res.push_back(curr);
    return true;
}   

string alienOrder(vector<string>& words) {
    int sz = words.size();
    if(sz == 0) return "";
    if(sz == 1) return words[0];
    unordered_map<char, unordered_set<char> > edges;
    vector<int> visited(26, 0);
    vector<int> char_set(26, 0);
    for(int i=0; i<sz-1; i++) build_edges(words[i], words[i+1], edges);
    for(string s:words){
        for(char c:s)
            if(char_set[c-'a'] == 0) char_set[c-'a']++;
    }
    string res = "";
    for(int i=0; i<26; i++){
        if(char_set[i] && visited[i] == 0){
            visited[i] = 1;
            bool x = search(edges, i+'a', visited, res);
            if(!x) return "";
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<string> words = {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    };    
//    vector<string> words = {
//        "z",
//        "z"
//    };

//    vector<string> words = {
//        "a",
//        "b",
//        "a"
//    };
//    vector<string> words = {
//        "wnlb"
//    };
    cout<<alienOrder(words)<<endl;
    return 0;
}