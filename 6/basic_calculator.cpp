/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:

"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function.
*/

#include "header.h"

long calc(long a, long b, char op){
    if(op == '+') return a+b;
    return a-b;
}

void push_num(stack<long>& nums, stack<char>& op, long n){
    if(op.empty()) nums.push(n);
    else{
        if(nums.empty() || op.top() == '(' || op.top() == ')') nums.push(n);
        else{
            long l = nums.top();
            nums.pop();
            nums.push(calc(l, n, op.top()));
            op.pop();
        }
    }
}

int calculate(string s) {
    stack<char> op;
    stack<long> nums;
    int sz = s.length();
    for(int i=0; i<sz; i++){
        char c = s[i];
        //cout<<c<<endl;
        if(c == ' ') continue;
        if(c == '(') op.push(c);
        else if(c == ')'){
            op.pop();
            long temp = nums.top();
            nums.pop();
            push_num(nums, op, temp);
        }
        else if(c == '+' || c == '-') op.push(c);
        else{
            string n = string(1,c);
            while(s[i+1] <='9' && s[i+1]>='0'){
                n+=s.substr(i+1, 1);
                i++;
            }
            push_num(nums, op, stoi(n));
        }
    }
    long temp = nums.top();
    nums.pop();
    push_num(nums, op, temp);
    return nums.top();
}

int main(){
    cout<<calculate("(1-(4-5+2)-3)+(6+8)")<<endl;
    cout<<calculate(" 21-1 + 2 ")<<endl;
    cout<<calculate("  2 ")<<endl;
    cout<<calculate("2147483647")<<endl;
    return 0;
}