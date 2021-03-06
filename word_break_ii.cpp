/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

#include "header.h"

/* using dfs
void search(string& s, int curr, unordered_set<string>& wordDict, vector<int>& pos, vector<string>& res, vector<vector<bool> >& m){
    if(curr == s.length()){
        string temp = "";
        int start = 0;
        for(int i=0; i<pos.size(); i++){
            temp += s.substr(start,pos[i]-start)+" ";
            start = pos[i];
        }
        if(pos.size() == 0) res.push_back(s);
        else res.push_back(temp.substr(0,temp.size()-1));
        return;
    }
    for(int i=curr; i<s.length(); i++){
        if(!m[curr][i]) continue;
        pos.push_back(i+1);
        search(s,i+1,wordDict,pos,res,m);
        pos.pop_back();
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict){
    vector<string> res;
    vector<int> pos;
    vector<vector<bool> > m(s.length(), vector<bool>(s.length(), false));
    int sz = s.length();
    for(int i=0; i<sz; i++)
        for(int j=i;j<sz; j++)
            if(wordDict.find(s.substr(i, j-i+1)) != wordDict.end()) m[i][j] = true;
    bool flag = false;
    for(int i=0; i<sz; i++)
        if(m[i][sz-1]) flag = true;
    if(!flag) return res;
    search(s, 0, wordDict, pos, res, m);
    return res;
}
*/

/*using bfs */

vector<string> wordBreak(string s, unordered_set<string>& wordDict){
    int sz = s.length();
    vector<string> res;
    if(sz == 0) return res;
    unordered_map<int,unordered_set<int> > m;
    queue<int> curr;
    queue<int> next;
    vector<vector<bool> > in_dict(sz, vector<bool>(sz, false));
    for(int i=0; i<sz; i++)
        for(int j=i; j<sz; j++)
            if(wordDict.find(s.substr(i,j-i+1)) != wordDict.end()) in_dict[i][j] = true;
    int x = 0;
    curr.push(-1);
    queue<int> arr[2] = {curr,next};
    while(!arr[x%2].empty()){
        int last_tail = arr[x%2].front();
        arr[x%2].pop();
        for(int i=last_tail+1; i<sz; i++){
            if(in_dict[last_tail+1][i]){
                m[last_tail].insert(i);
                arr[(x+1)%2].push(i);
            }
        }
        if(arr[x%2].empty()) x++;
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        cout<<i->first<<": ";
        for(auto j=i->second.begin(); j!=i->second.end(); j++)
            cout<<*j<<" ";
        cout<<endl;
    }
    return res;
}

int main(){
    vector<string> res;
    unordered_set<string> dict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
//    unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"});
//    string s("catsanddog");
    string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    res = wordBreak(s,dict);
    for(int i=0; i<res.size(); i++)
        std::cout<<res[i]<<std::endl;
    return 0;
}
