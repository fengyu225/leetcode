/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include "header.h"

void gen(int left_count, int close_count, string& s, vector<string>& res, int n){
    if(close_count == n){
        res.push_back(s);
        return;
    }
    if(left_count+close_count<n){
        s+='(';
        gen(left_count+1, close_count, s, res, n);
        s.pop_back();
    }        
    if(left_count>0){
        s+=')';
        gen(left_count-1, close_count+1, s, res, n);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n == 0) return res;
    int left_count = 0;
    string s = "";
    gen(left_count, 0, s, res, n);
    return res;
}

int main(){
    vector<string> res = generateParenthesis(3);
    for(int i=0; i<res.size(); i++)
        printf("%s\n", res[i].c_str());
    return 0;
}
