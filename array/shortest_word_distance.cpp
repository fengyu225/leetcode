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
    int pos1 = -1, pos2 = -1, res = sz+1;
    for(int i = 1; i<sz; i++){
        if(words[i-1] == word1) pos1 = i-1;
        if(words[i-1] == word2) pos2 = i-1;
        if(words[i] == word1 && pos2>-1) res = min(res, i-pos2);
        if(words[i] == word2 && pos1>-1) res = min(res, i-pos1);
    }
    return res;
}

//["this","is","a","long","sentence","is","fun","day","today","sunny","weather","is","a","day","tuesday","this","sentence","run","running","rainy"]
//"weather"
//"long"

int main(){
    //["a","c","b","b","a"], "a", "b"
//    string arr[] = {"practice", "makes", "perfect", "coding", "makes"};
//    vector<string> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
//    cout<<shortestDistance(v_arr, "coding", "practice")<<endl;
//    cout<<shortestDistance(v_arr, "makes", "coding")<<endl;
    
    //string arr[] = {"a","c","b","b","a"};
    string arr[] = {"this","is","a","long","sentence","is","fun","day","today","sunny","weather","is","a","day","tuesday","this","sentence","run","running","rainy"};
    vector<string> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<shortestDistance(v_arr, "weather", "long")<<endl;
    return 0;
}