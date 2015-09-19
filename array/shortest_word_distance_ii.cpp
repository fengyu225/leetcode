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
public:
    WordDistance(vector<string>& words) {
        int sz = words.size();
        for(int i = 0; i<sz; i++){
            if(m.find(words[i]) == m.end()) m[words[i]] = vector<int>();
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> left = m[word1];
        vector<int> right = m[word2];
        int l = 0, r = 0, res = INT_MAX;
        while(l<left.size() && r<right.size()){
            res = min(res, abs(left[l]-right[r]));
            if(left[l]<right[r]) l++;
            else if(left[l]>right[r]) r++;
            else{
                l++;
                r++;
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<int> > m;
};

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

int main(){
    string arr[] = {"practice", "makes", "perfect", "coding", "makes"};
    vector<string> words(arr, arr+sizeof(arr)/sizeof(arr[0]));
    WordDistance wordDistance(words);
    cout<<wordDistance.shortest("coding", "practice")<<endl;
    cout<<wordDistance.shortest("makes", "coding")<<endl;
    return 0;
}