/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include "header.h"

int evalRPN(vector<string>& tokens) {
    int sz = tokens.size();
    stack<int> s;
    for(int i=0; i<sz; i++){
        if(tokens[i] == "+"){
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            s.push(l+r);
        }
        else if(tokens[i] == "-"){
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            s.push(l-r);
        }
        else if(tokens[i] == "*"){
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            s.push(l*r);
        }
        else if(tokens[i] == "/"){
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            s.push(l/r);
        }
        else s.push(stoi(tokens[i]));
    }
    return s.top();
}

int main(){
    //vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"-1","1","*","-1","+"};
    cout<<evalRPN(tokens)<<endl;
    return 0;
}
