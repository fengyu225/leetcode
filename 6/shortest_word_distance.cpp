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

int shortestDistance(vector<string>& words, string word1, string word2) {
    int sz = words.size();
    int word1_last = -1, word2_last = -1;
    int res = sz+1;
    for(int i=0; i<sz; i++){
        string w = words[i];
        if(w != word1 && w != word2) continue;
        if(w == word1){
            if(word2_last>=0) res = min(res, i-word2_last);
            word1_last = i;
        }
        else if(w == word2){
            if(word1_last>=0) res = min(res, i-word1_last);
            word2_last = i;
        }
    }
    return res;
}

int main(){
    //["a","c","b","b","a"], "a", "b"
//    string arr[] = {"practice", "makes", "perfect", "coding", "makes"};
//    vector<string> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
//    cout<<shortestDistance(v_arr, "coding", "practice")<<endl;
//    cout<<shortestDistance(v_arr, "makes", "coding")<<endl;
    
    string arr[] = {"a","b","c","d", "d", "d"};
    vector<string> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<shortestDistance(v_arr, "a", "d")<<endl;
    return 0;
}