/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

#include "header.h"

void search(string& s, int curr, vector<vector<bool> >& in_dict, vector<int>& pos, vector<string>& res){
    if(curr == s.length()){
        string temp = s;
        for(int i=0; i<pos.size(); i++) temp.insert(temp.begin()+pos[i]+i+1, ' ');
        if(pos.size() > 0) temp.pop_back();
        res.push_back(temp);
        return;
    }
    for(int i=curr; i<s.length(); i++){
        //cout<<s.substr(curr, i-curr+1)<<": "<<in_dict[curr][i]<<endl;
        if(in_dict[curr][i]){
            pos.push_back(i);
            search(s, i+1, in_dict, pos, res);
            pos.pop_back();
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int s_len = s.length();
    vector<vector<bool> > in_dict(s_len, vector<bool>(s_len, false));
    for(int i=0; i<s_len; i++){
        for(int j=i; j<s_len; j++){
            string temp = s.substr(i, j-i+1);
            if(wordDict.find(temp) == wordDict.end()) in_dict[i][j] = false;
            else in_dict[i][j]=true;
        }
    }
    bool flag = false;
    for(int i=0; i<s_len; i++){
        if(in_dict[i][s_len-1]){
            flag = true;
            break;
        }
    }
    vector<string> res;
    if(!flag) return res;
    vector<int> pos;
    search(s, 0, in_dict, pos, res);
    return res;
}

int main(){
    vector<string> res;
//    unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"});
//    string s("catsanddog");
    unordered_set<string> dict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
    string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    res = wordBreak(s,dict);
    for(int i=0; i<res.size(); i++)
        std::cout<<"|"<<res[i]<<"|"<<std::endl;
    return 0;
}
