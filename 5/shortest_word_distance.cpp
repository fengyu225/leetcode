/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include "header.h"

int shortestDistance(vector<string>& words, string word1, string word2){
    int sz = words.size();
    unordered_map<string, vector<int> > map;
    for(int i=0; i<sz; i++){
        if(map.find(words[i]) == map.end()) map[words[i]] = vector<int>();
        map[words[i]].push_back(i);
    }
    int res = INT_MAX;
    for(int i=0; i<map[word1].size(); i++){
        for(int j=0; j<map[word2].size(); j++)
            res = min(res, abs(map[word1][i] - map[word2][j]));
    }
    return res;
}

int main(){
    //["a","c","b","b","a"], "a", "b"
//    string arr[] = {"practice", "makes", "perfect", "coding", "makes"};
//    vector<string> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
//    cout<<shortestDistance(v_arr, "coding", "practice")<<endl;
//    cout<<shortestDistance(v_arr, "makes", "coding")<<endl;
    
    string arr[] = {"a","c","b","b","a"};
    vector<string> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<shortestDistance(v_arr, "a", "b")<<endl;
    return 0;
}