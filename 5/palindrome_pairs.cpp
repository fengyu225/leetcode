/*
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

#include "header.h"

bool is_palindrome(string& s){
    int l = 0, r=s.length()-1;
    while(l<r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

vector<vector<int> > palindromePairs(vector<string>& words) {
    vector<vector<int> > res;
    unordered_map<string,int> pos;
    unordered_set<string> palins;
    int sz = words.size();
    for(int i=0; i<sz; i++){
        pos[words[i]] = i;
        if(is_palindrome(words[i])) palins.insert(words[i]);
    }
    for(int i=0; i<sz; i++){
        int len = words[i].length();
        string temp = words[i];
        reverse(temp.begin(), temp.end());
        if(pos.find(temp) != pos.end() && pos[temp] != i)
            res.push_back(vector<int>({pos[temp], i}));
        for(int j=1; j<=len; j++){
            string a = words[i].substr(0, j);
            if(!is_palindrome(a)) continue;
            string b = words[i].substr(j, len-j);
            reverse(b.begin(), b.end());
            if(pos.find(b) != pos.end() && pos[b] != i)
                res.push_back(vector<int>({pos[b], i})); 
        }
        if(len == 0){
            for(string w : palins)
                if(pos[w] != i)
                    res.push_back(vector<int>({pos[w], i}));
        }
    }
    return res;
}

int main(){
//    vector<string> words = {"bat", "tab", "cat"};
//    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
//    vector<string> words = {"a",""};
    vector<string> words = {"a","b","c","ab","ac","aa"};
    //[[3,0],[1,3],[4,0],[2,4],[5,0],[0,5]]
    vector<vector<int> > res = palindromePairs(words);
    for(auto v : res) print_vector<int>(v);
    return 0;
}
