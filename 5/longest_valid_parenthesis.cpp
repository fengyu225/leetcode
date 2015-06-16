/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include "header.h"


int longestValidParentheses(string s) {
    int sz = s.length();
    if(sz<2) return 0;
    stack<int> stack;
    int res = 0;
    stack.push(-1);
    for(int i=0; i<sz; i++){
        if(s[i] == '(') stack.push(i);
        else if(stack.top() != -1 && s[stack.top()]=='('){
            stack.pop();
            res = max(res, i-stack.top());
        }
        else stack.push(i);
    }
    return res;
}

//int longestValidParentheses(string s) {
//    int sz = s.length();
//    if(sz<2) return 0;
//    stack<int> stack;
//    int res = 0;
//    int begin = -1;
//    for(int i=0; i<sz; i++){
//        if(s[i] == '(') stack.push(i);
//        else{
//            if(stack.empty()){
//                begin = i;
//                continue;
//            } 
//            stack.pop();
//            if(stack.empty())
//                res = max(res,i-begin);
//            else
//                res = max(res, i-stack.top());
//        }
//    }
//    return res;
//}

int main(){
    //string s0("()(()))()())");
    string s0(")()())");
    printf("%d\n", longestValidParentheses(s0));
    string s1("(()");
    printf("%d\n", longestValidParentheses(s1));
    string s2("");
    printf("%d\n", longestValidParentheses(s2));
    return 0;
}
