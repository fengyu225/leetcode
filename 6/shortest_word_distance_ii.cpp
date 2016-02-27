/*
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include "header.h"

class WordDistance {
    unordered_map<string,vector<int> > pos;
    int sz;
public:
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            pos[words[i]].push_back(i);
        } 
        sz = words.size();
    }

    int shortest(string word1, string word2) {
        vector<int> word1_pos = pos[word1];
        vector<int> word2_pos = pos[word2];
        int a = 0, b = 0, res = sz+1;
        if(word1 == word2) for(int i=0; i<word1_pos.size()-1; res=min(res, word1_pos[i+1]-word1_pos[i]), i++);
        else{
            while(a<word1_pos.size() && b<word2_pos.size()){
                int diff = word1_pos[a]-word2_pos[b];
                res = min(res, abs(diff));
                if(diff<0) a++;
                else b++;
            }
        }
        return res;
    }
};

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

int main(){
    string arr[] = {"practice", "makes", "perfect", "coding", "makes", "makes"};
    vector<string> words(arr, arr+sizeof(arr)/sizeof(arr[0]));
    WordDistance wordDistance(words);
//    cout<<wordDistance.shortest("coding", "practice")<<endl;
//    cout<<wordDistance.shortest("makes", "coding")<<endl;
    cout<<wordDistance.shortest("makes", "makes")<<endl;
    return 0;
}