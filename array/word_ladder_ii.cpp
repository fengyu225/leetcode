/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include "header.h"



int main(){
    string start("hit");
    string end("cog");
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    vector<vector<string> > r = findLadders(start,end,dict);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%s ", r[i][j].c_str());
        printf("\n");
    }
    return 0;
}
