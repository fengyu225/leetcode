/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/

#include "header.h"

int calculate(string s) {
    s = "("+s+")";
    int sz = s.length();
    stack<long> st;
    stack<char> ops;
    for(int i=0; i<sz; i++){
        if(s[i] == ' ') continue;
        if(s[i]<='9' && s[i]>='0'){
            int n = i+1;
            string num(1, s[i]);
            while(n<sz && s[n]<='9' && s[n]>='0') num += s[n++];
            i = n-1;
            if(!ops.empty() && (ops.top() == '+' || ops.top() == '-')){
                long l = st.top();
                st.pop();
                if(ops.top() == '+') st.push(l+stol(num));
                if(ops.top() == '-') st.push(l-stol(num));
                ops.pop();
            }
            else st.push(stol(num));
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '(') ops.push(s[i]);
        else{
            ops.pop();
            if(!ops.empty() && (ops.top() == '+' || ops.top() == '-')){
                long r = st.top();
                st.pop();
                long l = st.top();
                st.pop();
                if(ops.top() == '+') st.push((l+r));
                if(ops.top() == '-') st.push((l-r));
                ops.pop();
            }
        }
    }
    return st.top();
}

int main(){
    cout<<calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
    cout<<calculate(" 2-1 + 2 ")<<endl;
    return 0;
}