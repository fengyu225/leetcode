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

long calc(long l, string op, long r){
    if(op == "+") return l+r;
    if(op == "-") return l-r;
}

string readToken(string s, int& curr){
    int sz = s.length();
    if(curr == sz) return "";
    string res = "";
    while(curr<sz){
        char c = s[curr++];
        if(c == ' ') continue;
        if(c == '(' || c == ')' || c == '+' || c == '-'){
            if(res.length() == 0) return string(1,c);
            else{
                curr--;
                break;
            }
        }
        res += c;
    }
    return res;
}

bool isNum(string& s){
    for(char c:s){
        if(c<='9' && c>='0') continue;
        else return false;
    }
    return true;
}

int calculate(string s){
    int sz = s.length();
    if(sz == 0) return 0;
    stack<long> nums;
    stack<string> ops;
    long curr_num = 0;
    string curr_ops="+"; 
    for(int i=0; i<sz; i++){
        char c = s[i];
        if(c == ' ') continue;
        if(c == '('){
            nums.push(curr_num);
            ops.push(curr_ops);
            curr_num = 0;
            curr_ops = "+";
        }
        else if(c == ')'){
            string o = ops.top(); ops.pop();
            long l = nums.top(); nums.pop();
            curr_num = calc(l, o, curr_num);
        }
        else if(c=='+' || c == '-') curr_ops = string(1,c);
        else{
            string temp(1,c);
            int r = i+1;
            while(r<sz && s[r]<='9' && s[r]>='0') temp+=s[r++];
            i = r-1;
            curr_num = calc(curr_num, curr_ops, stol(temp));
        }
    }
    return curr_num;
}

//int calculate(string s){
//    int sz = s.length();
//    if(sz == 0) return 0;
//    stack<string> stack;
//    string curr = "";
//    int curr_idx = 0;
//    while(1){
//        curr=readToken(s, curr_idx);
//        if(curr == "") break;
//        cout<<curr<<endl;
//        if(isNum(curr)){
//            if(!stack.empty() && (stack.top() == "+" || stack.top()== "-")){
//                string x = stack.top();
//                stack.pop();
//                long l = stol(stack.top());
//                stack.pop();
//                stack.push(to_string(calc(l, x, stol(curr))));
//            }
//            else stack.push(curr);
//        }
//        else if(curr == ")"){
//            string temp = stack.top();
//            stack.pop();
//            stack.pop();
//            if(!stack.empty() && (stack.top() == "+" || stack.top() == "-")){
//                string op = stack.top();
//                stack.pop();
//                string l = stack.top();
//                stack.pop();
//                temp = to_string(calc(stol(l), op, stol(temp)));
//            }
//            stack.push(temp);
//        }
//        else stack.push(curr);
//    }
//    return stack.empty()?0:stoi(stack.top()); 
//}

int main(){
//    cout<<calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
//    cout<<calculate(" 21-1 + 2 ")<<endl;
//    cout<<calculate("  2 ")<<endl;
    cout<<calculate("2147483647")<<endl;
    return 0;
}