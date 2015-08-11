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
            for(int i=0;i<sz; i++){
                if(map.find(words[i]) == map.end()) map[words[i]] = vector<int>();
                map[words[i]].push_back(i);
            }
        }
        
        int shortest(string word1, string word2) {
            vector<int> idx1 = map[word1];
            vector<int> idx2 = map[word2];
            int idx1_sz = idx1.size(), idx2_sz = idx2.size();
            int res = INT_MAX;
            int curr_1 = 0, curr_2 = 0;
            while(curr_1<idx1_sz && curr_2<idx2_sz){
                res = min(res, abs(idx1[curr_1]-idx2[curr_2]));
                if(idx1[curr_1]<idx2[curr_2]) curr_1++;
                else curr_2++;
            }
            return res;
        }
         
//        int shortest(string word1, string word2) {
//            vector<int> idx1 = map[word1];
//            vector<int> idx2 = map[word2];
//            int res = INT_MAX;
//            for(int i=0; i<idx1.size(); i++){
//                for(int j=0; j<idx2.size(); j++)
//                    res = min(res, abs(idx1[i]-idx2[j]));
//            }
//            return res;
//        }
    private:
        unordered_map<string, vector<int> > map;
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