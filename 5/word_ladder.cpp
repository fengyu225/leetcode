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

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict){
    int res = 1;
    if(beginWord == endWord) return res;
    queue<string> curr;
    queue<string> next;
    curr.push(beginWord);
    queue<string> arr[2] = {curr,next};
    unordered_set<string> has_seen;
    has_seen.insert(beginWord);
    int x = 0;
    while(!arr[x%2].empty()){
        string temp = arr[x%2].front();
        arr[x%2].pop();
        for(int i=0; i<temp.length(); i++)
            for(int j='a'; j<='z'; j++){
                char c = temp[i];
                if(c == j) continue;
                temp[i] = j;
                if(temp == endWord) return res+1;
                if(wordDict.find(temp) != wordDict.end()){
                    arr[(x+1)%2].push(temp);
                    wordDict.erase(temp);
                }
                temp[i] = c;
            }
        if(arr[x%2].empty()){
            res++;
            x++;
        }
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
