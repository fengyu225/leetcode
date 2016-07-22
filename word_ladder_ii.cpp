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

void get_res(unordered_map<string, vector<string> >& m, string& start, string& end, vector<vector<string> >& res, vector<string>& vt){
    if(end == start){
        vt.push_back(end);
        reverse(vt.begin(), vt.end());
        res.push_back(vt);
        return;
    }
    vector<string> temp = m[end];
    vector<string> vvv =vt;
    for(auto i=temp.begin(); i!=temp.end(); i++){
        vt.push_back(end);
        get_res(m, start, *i, res, vt);
        vt.pop_back();
    }
    vt = vvv;
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict){
    unordered_map<string, vector<string> > m;
    queue<string> curr;
    queue<string> next;
    curr.push(start);
    queue<string> arr[2]={curr,next};
    int x=0;
    while(!arr[x%2].empty()){
        string temp = arr[x%2].front();
        arr[x%2].pop();
        for(int i=0; i<temp.length(); i++)
            for(int j='a';j<='z';j++){
                string t = temp;
                char c = temp[i];
                if(c == j) continue;
                temp[i] = j;
                if(temp == end) m[end].push_back(t);
                if(dict.find(temp) != dict.end()){
                    arr[(x+1)%2].push(temp);
                    dict.erase(temp);
                    m[temp].push_back(t); 
                }
                temp[i] = c;
            }
        if(arr[x%2].empty()) x++;
    }
    vector<vector<string> > res;
    vector<string> vt;
    get_res(m,start,end,res,vt);
    return res;
}

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
