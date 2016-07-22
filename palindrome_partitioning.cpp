/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

#include "header.h"

bool is_valid(string s){
    int l = 0, r=s.length()-1;
    while(l<r){
        if(s[l] != s[r]) return false;
        l++;r--;
    }
    return true;
}

void search(string& s, int curr, vector<int>& pos, vector<vector<string> >& res){
    if(curr == s.length()){
        vector<string> temp;
        if(pos.size() == 0 && is_valid(s)) temp.push_back(s);
        if(pos.size() > 0 && pos.back()==s.length()-1){
            int left = 0;
            for(int i=0; i<pos.size(); i++){
                temp.push_back(s.substr(left,pos[i]-left+1));
                left = pos[i]+1;
            }
        }
        if(temp.size() > 0) res.push_back(temp);
        return;
    }
    for(int i=curr; i<s.length(); i++){
        string x = s.substr(curr, i-curr+1);
        if(is_valid(x)){
            pos.push_back(i);
            search(s,i+1,pos,res);
            pos.pop_back();
        }
    }
}

vector<vector<string> > partition(string s){
    vector<vector<string> > res;
    int sz = s.length();
    if(sz == 0) return res;
    vector<int> pos;
    search(s, 0, pos, res);
    return res;
}

int main(){
   //string s("aab");
   string s("aab");
   vector<vector<string> > r = partition(s);
   for(int i=0; i<r.size(); i++){
       for(int j=0; j<r[i].size(); j++)
           printf("%s ", r[i][j].c_str());
       printf("\n");
   }
   return 0;
}
