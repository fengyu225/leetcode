#include "header.h"

bool is_valid_p(string s){
    int l = 0;
    int r = s.size()-1;
    while(l<r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void solve(string s, int curr, vector<string>& v, vector<vector<string> >& res){
    if(curr == s.size()){
        res.push_back(v);
        return ;
    }
    for(int i=curr; i<s.size(); i++){
        string x = s.substr(curr,i-curr+1);
        if(is_valid_p(x)){
            v.push_back(x);
            solve(s,i+1,v,res);
            v.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > res;
    vector<string> v;
    solve(s,0,v,res);
    return res;
}


int main(){
   //string s("aab");
   string s("aab");
   vector<vector<string> > r;
   r = partition(s);
   for(int i=0; i<r.size(); i++){
       for(int j=0; j<r[i].size(); j++)
           printf("%s ", r[i][j].c_str());
       printf("\n");
   }
   return 0;
}
