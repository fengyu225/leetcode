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
    int w1_index = -1, w2_index = -1;
    int res = sz+1;
    for(int i=0; i<sz; i++){
        string w = words[i];
        if(w != word1 && w != word2) continue;
        bool a = (w == word1), b = (w == word2);
        if(a) res = min(res, w2_index>=0?i-w2_index:sz+1); 
        if(b) res = min(res, w1_index>=0?i-w1_index:sz+1); 
        if(a) w1_index = i;
        if(b) w2_index = i;
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