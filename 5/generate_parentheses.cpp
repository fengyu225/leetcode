/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include "header.h"

vector<string> generateParenthesis(int n) {
}

int main(){
    vector<string> res = generateParenthesis(3);
    for(int i=0; i<res.size(); i++)
        printf("%s\n", res[i].c_str());
    return 0;
}
