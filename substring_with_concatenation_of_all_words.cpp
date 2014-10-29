/*
 *  You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 

*/

#include "header.h"

vector<int> findSubstring(string S, vector<string>& L){
    unordered_map<string,int> dict;
    unordered_map<string,int> found;
    int l_size = L.size(), l_w_size = L[0].size(), s_size = S.size();
    vector<int> res;
    if(s_size == 0 || s_size<l_w_size*l_size) return res;
    for(int i=0; i<l_size; i++){
        dict[L[i]]++;
        found[L[i]]=0;
    }
    for(int i=0; i+l_w_size*l_size-1<S.size(); i++){
        found.clear();
        bool flag = true;
        for(int j=i;j<i+l_w_size*l_size;j+=l_w_size){
            string w = S.substr(j,l_w_size);
            found[w]++;
            if(found[w]>dict[w]){
                flag = false;
                break;
            }
        }
        if(flag)
            res.push_back(i);
    }
    return res;
}

int main(){
//    string S("barfoothefoobarman");
//    string l0("foo");
//    string l1("bar");
    string S("aaa");
    string l0("a");
    string l1("a");
    vector<string> L;
    L.push_back(l0);
    L.push_back(l1);
    vector<int> r = findSubstring(S,L);
    for(int i=0; i<r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}
