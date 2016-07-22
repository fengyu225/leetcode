/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include "header.h"

void search(int n, int curr_open, int balanced, string& temp, vector<string>& res){
    if(curr_open == 0 && balanced == n){
        res.push_back(temp);
        return;
    }
    if(curr_open+balanced>n) return;
    string orig = temp;
    if(curr_open>0){
        temp += ")";
        search(n, curr_open-1, balanced+1, temp, res);
        temp = orig;
    }
    temp += "(";
    search(n, curr_open+1, balanced, temp, res);
    temp = orig;
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string temp = "";
    search(n, 0, 0, temp, res);
    return res;
}

int main(){
    vector<string> res = generateParenthesis(3);
    for(int i=0; i<res.size(); i++)
        printf("%s\n", res[i].c_str());
    return 0;
}
