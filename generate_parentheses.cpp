#include "header.h"

void gen_p(vector<string>& res, int n_open, int n_pair, int n, string s){
    if(n_open>n-n_pair) return;
    if(n_open == n-n_pair){
        for(int i=0;i<n_open;i++) s+= ")";
        res.push_back(s);
        return;
    }
    if(n_open>=1){
        s += ")";
        gen_p(res,n_open-1,n_pair+1,n,s);
        s = s.substr(0,s.size()-1);
    }
    s+="(";
    gen_p(res,n_open+1,n_pair,n,s);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n==0) return res; 
    string s;
    gen_p(res,0,0,n,s);
    return res;
}

int main(){
    vector<string> res = generateParenthesis(10000);
    for(int i=0; i<res.size(); i++)
        printf("%s\n", res[i].c_str());
    return 0;
}
