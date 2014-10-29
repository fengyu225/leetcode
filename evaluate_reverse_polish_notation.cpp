#include "header.h"

int evalRPN(vector<string> &tokens) {
}

int main(){
    //vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"-1","1","*","-1","+"};
    cout<<evalRPN(tokens)<<endl;
    return 0;
}
