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

void calc_order(string& curr, string& next, vector<string>& m){
    int sz = min(curr.length(), next.length());
    for(int i=0; i<sz; i++){
        if(curr[i] == next[i]) continue;
        char p = curr[i], n = next[i];
        if(m[p-'a'].find(n) == string::npos) m[p-'a'] += n;
        break;
    }
}

bool topo_sort(vector<string>& m, int curr, string& res, vector<bool>& visited){
    if(visited[curr]) return false;
    visited[curr] = true;
    for(char c:m[curr]){
        //cout<<(char)(curr+'a')<<c<<endl;
        bool temp = topo_sort(m, c-'a', res, visited);
        if(!temp) return false;
    }
    res += (char)(curr+'a');
    return true;
}

string alienOrder(vector<string>& words) {
    vector<string> m(26, "");
    vector<bool> occur(26, false);
    int sz = words.size();
    if(sz == 1) return "";
    for(int i=0; i<sz-1; i++) calc_order(words[i], words[i+1], m);
    for(int i=0; i<sz; i++)
        for(char c:words[i]) occur[c-'a'] = true;
    string res = "";
    vector<bool> visited(26, false);
    bool correct = true;
    for(int i=0; i<26; i++){
        if(m[i].length() != 0 && !visited[i]) correct &= topo_sort(m, i, res, visited);
    }
    if(!correct) return "";
    reverse(res.begin(), res.end());
    for(int i=0; i<26; i++)
        if(!visited[i] && occur[i]) res += (char)(i+'a');
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
    cout<<alienOrder(words)<<endl;
    return 0;
}