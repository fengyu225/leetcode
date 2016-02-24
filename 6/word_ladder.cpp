/*
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include "header.h"

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    int w_len = beginWord.size(), res = 0;
    if(wordList.size() == 0) return 0;
    if(beginWord == endWord) return 1;
    queue<string> qs[2];
    qs[0].push(beginWord);
    while(!qs[res%2].empty()){
        string temp = qs[res%2].front();
        qs[res%2].pop();
        string x = temp;
        for(int i=0; i<w_len; i++){
            for(char c = 'a'; c<='z'; c++){
                if(temp[i] == c) continue;
                if(x == endWord) return res+2;
                x = temp;
                x[i] = c;
                if(wordList.find(x) != wordList.end()){
                    wordList.erase(wordList.find(x));
                    qs[(res+1)%2].push(x);
                }
            }
        }
        if(qs[res%2].empty()) res++;
    }
    return 0;
}

int main(){
    string start("hit");
    string end("cog");
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    printf("%d\n", ladderLength(start,end,dict));
    return 0;
}
