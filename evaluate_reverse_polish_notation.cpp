#include "header.h"

int evalRPN(vector<string> &tokens) {
    int res;
    stack<int> s;
    for(auto t:tokens){
        if(!(t=="+" || t=="-" || t=="*" || t=="/")){
            s.push(std::stoi(t));
            continue;
        }
        int r =  s.top();
        s.pop();
        int l = s.top();
        s.pop();
        if(t=="+")
            s.push(r+l);
        else if(t=="-")
            s.push(l-r);
        else if(t=="*")
            s.push(l*r);
        else
            s.push(l/r);
    }
    return s.top();
}

int main(){
    //vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"-1","1","*","-1","+"};
    cout<<evalRPN(tokens)<<endl;
    return 0;
}
