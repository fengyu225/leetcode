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
    if(beginWord == endWord) return 0;
    queue<string> qs[2];
    int curr = 0;
    qs[curr%2].push(beginWord);
    while(!qs[curr%2].empty()){
        string temp = qs[curr%2].front();
        qs[curr%2].pop();
        for(int i=0; i<temp.length(); i++){
            char orig = temp[i];
            for(int j='a'; j<='z'; j++){
                temp[i] = j;
                if(j == orig) continue;
                if(temp == endWord) return curr+2;
                if(wordList.find(temp) == wordList.end()) continue;
                qs[(curr+1)%2].push(temp);
                string mm = temp;
                mm[i] = orig;
                wordList.erase(wordList.find(temp));
            }
            temp[i] = orig;
        }
        if(qs[curr%2].empty()) curr++;
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
