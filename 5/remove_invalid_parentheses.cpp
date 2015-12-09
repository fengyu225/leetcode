/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

#include "header.h"

void search(string& s, unordered_set<string>& res_set, string& temp, int curr, int open, int s_sz, int& max_valid_len){
    //dfs
    if(s_sz-curr<open) return;
    if(curr == s_sz){
        if(temp.length()>=max_valid_len && res_set.find(temp) == res_set.end()){
            max_valid_len = temp.length();
            res_set.insert(temp);
        }
        return;
    }    
    if(s[curr] != '(' && s[curr] != ')'){
        temp += s[curr];
        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len);
        temp.pop_back();
        return;
    }
    if(s[curr] == '('){
        temp += "(";
        search(s, res_set, temp, curr+1, open+1, s_sz, max_valid_len);
        temp.pop_back();
        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len);
    }
    else{
        if(!(s[curr] == ')' && open==0)){
            temp += ')';
            search(s, res_set, temp, curr+1, open-1, s_sz, max_valid_len);
            temp.pop_back();
        }
        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len);
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    int sz = s.length();
    unordered_set<string> res_set;
    string temp = "";
    int max_valid_len = 0;
    search(s, res_set, temp, 0, 0, sz, max_valid_len);
    for(string a:res_set) res.push_back(a);
    return res;
}

int main(){
//    vector<string> res = removeInvalidParentheses("()())()");
//    vector<string> res = removeInvalidParentheses("(a)())()");
//    vector<string> res = removeInvalidParentheses(")()");
//    vector<string> res = removeInvalidParentheses("(");
//    vector<string> res = removeInvalidParentheses(")");
//    string input = "";
//    for(int i=0; i<10; i++) input.append("(");
//    for(int i=0; i<9; i++) input.append(")");
    vector<string> res = removeInvalidParentheses("(()()))q(l)()o)(z");
    cout<<res.size()<<endl;
    for(string temp:res){
        cout<<temp<<endl;
    }
    return 0;
}