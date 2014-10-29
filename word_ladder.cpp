/*
 *  Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

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

using namespace std;

int ladderLength(string start,string end, unordered_set<string>& dict){
    queue<string> curr;
    queue<string> next;
    curr.push(start);
    queue<string> qs[2] = {curr,next};
    int level = 0;
    int res = 1;
    while(!qs[level%2].empty()){
        string x = qs[level%2].front();
        qs[level%2].pop();
        for(int i=0; i<x.size(); i++){
            char c = x[i];
            for(int j=0;j<26;j++){
                x[i] = 'a'+j;
                if(x[i] == c) continue;
                if(x==end) return res+1;
                if(dict.find(x) != dict.end()){
                    qs[(level+1)%2].push(x);
                    dict.erase(x);
                }
            }
            x[i] = c;
        }
        if(qs[level%2].empty()){
            level++;
            res++;
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
