/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include "header.h"


int longestValidParentheses(string s) {
    int s_len = s.length();
    stack<int> st;
    int res = 0;
    for(int i=0; i<sz; i++){
        if(s[i] == '(') st.push(i);
        else{
            if(st.empty()) st.push(i);
            else{
                if(s[st.top()] == '('){
                    st.pop();
                    res = max(res, i-(st.empty()?-1:st.top()));
                }
                else st.push(i);
            }
        }
    }
    return res;
}

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
