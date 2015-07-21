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

//int calculate(string& s, int l, int r){
//    if(l == r) return stoi(s.substr(l,1));
//    vector<int> plus_pos;
//    vector<int> minus_pos;
//    for(int i=l; i<=r; i++){
//        if(s[i] == '+') plus_pos.push_back(i);
//        if(s[i] == '-') minus_pos.push_back(i);
//    }
//    int res = 0;
//    if(plus_pos.size()>0){
//        plus_pos.push_back(r+1);
//        int curr_l = l;
//        for(int i=0; i<plus_pos.size(); i++){
//            res += calculate(s, curr_l, plus_pos[i]-1); 
//            curr_l = plus_pos[i]+1;
//        }
//        return res;
//    }
//    if(minus_pos.size()>0){
//        minus_pos.push_back(r+1);
//        res = calculate(s, l, minus_pos[0]-1);
//        int curr_l = minus_pos[0]+1;
//        for(int i=1; i<minus_pos.size(); i++){
//            res -= calculate(s, curr_l, minus_pos[i]-1); 
//            curr_l = minus_pos[i]+1;
//        }
//        return res;
//    }
//    int curr_res = -1; string curr_ops="";
//    for(int i=l; i<=r; i++){
//        string temp = s.substr(i,1);
//        if(temp == " ") continue;
//        else if(temp == "*" || temp == "/") curr_ops = temp;
//        else{
//            int curr_r = i+1;
//            while(curr_r<=r && s[curr_r]<='9' && s[curr_r]>='0') temp+=s[curr_r++];
//            i = curr_r-1;
//            if(curr_ops.length() > 0){
//                curr_res = curr_ops == "*"?curr_res*(stoi(temp)):curr_res/(stoi(temp));
//                curr_ops = "";
//            }
//            else curr_res = stoi(temp);
//        }
//    }
//    return curr_res;
//}
//
//int calculate(string s) {
//    int sz = s.length();
//    if(sz == 0) return 0;
//    return calculate(s,0,sz-1);
//}

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
//    cout<<calculate("3+2*2")<<endl;
//    cout<<calculate("3/2")<<endl;
//    cout<<calculate("3+5 / 2")<<endl;
    //cout<<calculate("1*2-3/4+5*6-7*8+9/10")<<endl;
    cout<<calculate("42")<<endl;
    return 0;
}