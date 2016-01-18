/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include "header.h"

int calc(int l, int r, string op){
    if(op == "+") return l+r;
    if(op == "-") return l-r;
    if(op == "*") return l*r;
    if(op == "/") return l/r;
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(string s:tokens){
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            int r = st.top();
            st.pop();
            int l = st.top();
            st.pop();
            st.push(calc(l, r, s));
        }
        else st.push(stoi(s));
    }
    return st.top();
}

int main(){
    //vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"-1","1","*","-1","+"};
    cout<<evalRPN(tokens)<<endl;
    return 0;
}
