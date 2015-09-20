/*
 *  You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 

*/

#include "header.h"

vector<int> findSubstring(string s, vector<string>& words){
    vector<int> res;
    if(words.size() == 0 || s.length() == 0) return res;
    int s_sz = s.length(), w_count = words.size(), w_len = words[0].length();
    if(s_sz<w_len*w_count) return res;
    unordered_map<string, int> dict;
    unordered_map<string, int> found;
    for(int i=0;i<w_count; i++)
        dict[words[i]]++;
    for(int i=0; i+w_count*w_len-1<s_sz;i++){
        bool flag = true;
        found.clear();
        for(int j=0; j<w_count*w_len; j+=w_len){
            string w = s.substr(i+j, w_len);
            found[w]++;
            if(found[w]>dict[w]){
                flag = false;
                break;
            }
        }
        if(flag) res.push_back(i);
    }
    return res;
}


int main(){
    string S("barfoothefoobarman");
    string l0("foo");
    string l1("bar");
//    string S("aaa");
//    string l0("a");
//    string l1("a");
    vector<string> L;
    L.push_back(l0);
    L.push_back(l1);
    vector<int> r = findSubstring(S,L);
    for(int i=0; i<r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}
