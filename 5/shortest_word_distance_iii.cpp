/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/

#include "header.h"

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int sz = words.size();
    int idx1 = -1, idx2 = -1, res = INT_MAX;
    bool same = word1==word2;
    for(int i=0; i<sz; i++){
        if(same && words[i] == word1){
            if(idx1 == -1) idx1 = i;
            else if(idx2 == -1) idx2 = i;
            else{
                idx1 = idx2;
                idx2 = i;
            }
        }
        else{
            if(words[i] == word1) idx1 = i;
            if(words[i] == word2) idx2 = i;
        }
        if(idx1>-1 && idx2>-1) res=min(res, abs(idx1-idx2));
    }
    return res;
}

int main(){
    string arr[] = {"practice", "makes", "perfect", "coding", "makes"};
    vector<string> words(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<shortestWordDistance(words, "makes", "coding")<<endl;
    cout<<shortestWordDistance(words, "makes", "makes")<<endl;
    return 0;
}