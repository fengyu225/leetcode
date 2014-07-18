#include "header.h"

void gen_p(vector<string>& res, int curr_l_num, int curr_num_pair, int n, string s){
    if(curr_l_num>n-curr_num_pair) return;
    if(curr_l_num+curr_num_pair == n){
        string temp = s;
        for(int i=0; i<curr_l_num; i++) temp+=")";
        res.push_back(temp);
        return ;
    }
    if(curr_l_num>=1){
        s+=")";
        gen_p(res,curr_l_num-1,curr_num_pair+1,n,s);
        s=s.substr(0,s.size()-1);
    }
    s+="(";
    gen_p(res,curr_l_num+1,curr_num_pair,n,s);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n==0) return res; 
    string s;
    gen_p(res,0,0,n,s);
    return res;
}

int main(){
    vector<string> res = generateParenthesis(1);
    for(int i=0; i<res.size(); i++)
        printf("%s\n", res[i].c_str());
    return 0;
}
