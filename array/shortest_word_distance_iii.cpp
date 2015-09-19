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
    int pos1 = -1, pos2 = -1, res = sz+1;
    for(int i=1; i<sz; i++){
        if(words[i-1] == word1) pos1 = i-1;
        if(words[i-1] == word2) pos2 = i-1;
        if(words[i] == word1 && pos2>-1) res = min(res, i-pos2);
        if(words[i] == word2 && pos1>-1) res = min(res, i-pos1);
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