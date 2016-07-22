/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add operators +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

// 3:24
#include "header.h"

void search(string& num, int curr, long long last_val, char last_op, int target, long long curr_res, string temp, unordered_set<string>& res){
    int sz = num.length();
    if(curr==sz){
        if(curr_res == target) res.insert(temp);
        return;
    }
    for(int i=curr; i<sz; i++){
        long long n = stol(num.substr(curr, i-curr+1));
        if(to_string(n).length() != (size_t)(i-curr+1)) continue;
        search(num, i+1, n, '+', target, curr_res+n, temp+"+"+num.substr(curr, i-curr+1), res);
        search(num, i+1, n, '-', target, curr_res-n, temp+"-"+num.substr(curr, i-curr+1), res);
        if(last_op == '-')
            search(num, i+1, last_val*n, '-', target, curr_res+last_val-last_val*n, temp+"*"+num.substr(curr, i-curr+1), res);
        if(last_op == '+')
            search(num, i+1, last_val*n, '+', target, curr_res-last_val+last_val*n, temp+"*"+num.substr(curr, i-curr+1), res);
        if(last_op == '*')
            search(num, i+1, n, '*', target, curr_res*n, temp+"*"+num.substr(curr, i-curr+1), res);
    }
}

vector<string> addOperators(string num, int target) {
    int sz = num.length();
    if(sz == 1) return num[0]-'0' == target?vector<string>(1, num):vector<string>(); 
    unordered_set<string> res;
    string temp = "";
    for(int i=1; i<=sz; i++){
        string x_str = num.substr(0, i);
        long long x = stol(x_str);
        if(to_string(x).length() != (size_t)i) continue;
        search(num, i, x, '+', target, x, num.substr(0, i), res);
    }
    vector<string> r;
    for(auto i:res) r.push_back(i);
    return r;
}

int main(){
//    vector<string> res = addOperators("123", 6);
    //vector<string> res = addOperators("00", 0);
    //vector<string> res = addOperators("2147483647", 2147483647);
//    vector<string> res = addOperators("109", 9);
//    vector<string> res = addOperators("232", 8);
    vector<string> res = addOperators("123456789", 45);
    print_vector<string>(res);
    return 0;
}