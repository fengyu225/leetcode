/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:

"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function.
*/

#include "header.h"


int calc(int l, string op, int r){
    if(op == "+") return l+r;
    if(op == "-") return l-r;
    if(op == "*") return l*r;
    if(op == "/") return l/r;
}

void func(stack<int>& nums, stack<string>& ops){
    string op = ops.top();
    ops.pop();
    int r = nums.top();
    nums.pop();
    int l = nums.top();
    nums.pop();
    nums.push(calc(l,op,r));
}

int calculate(string s) {
    int sz = s.length();
    if(sz == 0) return 0;
    stack<int> nums;
    stack<string> ops;
    for(int i=0; i<sz; i++){
        char c = s[i];
        if(c == ' ') continue;
        else if(c<='9' && c>='0'){
            string temp(1,c);
            int r_idx = i+1;
            while(r_idx<sz && s[r_idx]<='9' && s[r_idx]>='0') temp+=s[r_idx++];
            i = r_idx-1;
            nums.push(stoi(temp));
        }
        else if(c == '+' || c=='-'){
            while(!ops.empty()) func(nums, ops);    
            ops.push(string(1,c));
        }
        else if(c == '*' || c=='/'){
            while(!ops.empty() && (ops.top() == "*" || ops.top() == "/")) func(nums, ops);
            ops.push(string(1,c));
        }
    }
    while(!ops.empty()) func(nums, ops);
    return nums.empty()?0:nums.top();
}

int main(){
    cout<<calculate("3+2*2")<<endl;
    cout<<calculate("3/2")<<endl;
    cout<<calculate("3+5 / 2")<<endl;
    cout<<calculate("1*2-3/4+5*6-7*8+9/10")<<endl;
    cout<<calculate("42")<<endl;
    return 0;
}