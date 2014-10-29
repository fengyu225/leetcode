#include "header.h"

int longestValidParentheses(string s) {
    if(s.size()<2) return 0;
    stack<int> stack;
    int res = 0;
    int begin = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            stack.push(i);
            continue;
        }
        if(stack.empty()){
            begin = i;
            continue;
        }
        stack.pop();
        if(stack.empty())
            res = std::max(res,i-begin);
        else
            res = std::max(res,i-stack.top());
    }
    return res;
}

int main(){
    string s0(")()())");
    printf("%d\n", longestValidParentheses(s0));
    string s1("(()");
    printf("%d\n", longestValidParentheses(s1));
    string s2("");
    printf("%d\n", longestValidParentheses(s2));
    return 0;
}
