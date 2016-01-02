/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

#include "header.h"

int string_bits(string& s){
    int res = 0, sz=s.length();
    for(int i=0; i<sz; i++){
        res |= (1<<(s[i]-'a'));
    }
    return res;
}

int maxProduct(vector<string>& words) {
    int sz = words.size();
    unordered_map<string,int> m;
    for(string s:words) m[s] = string_bits(s);
    int res = 0;
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++)
            if((m[words[i]] & m[words[j]]) == 0){
                int temp = words[i].length()*words[j].length();
                res = max(res, temp);
            }
    }
    return res;
}

int main(){
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout<<maxProduct(words)<<endl;
    return 0;
}