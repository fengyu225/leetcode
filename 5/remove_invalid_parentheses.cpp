/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

#include "header.h"

//void search(string& s, unordered_set<string>& res_set, string& temp, int curr, int open, int s_sz, int& max_valid_len){
//    //dfs
//    if(s_sz-curr<open) return;
//    if(curr == s_sz){
//        if(temp.length()>=max_valid_len && res_set.find(temp) == res_set.end()){
//            max_valid_len = temp.length();
//            res_set.insert(temp);
//        }
//        return;
//    }    
//    if(s[curr] != '(' && s[curr] != ')'){
//        temp += s[curr];
//        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len);
//        temp.pop_back();
//        return;
//    }
//    if(s[curr] == '('){
//        temp += "(";
//        search(s, res_set, temp, curr+1, open+1, s_sz, max_valid_len);
//        temp.pop_back();
//        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len);
//    }
//    else{
//        if(!(s[curr] == ')' && open==0)){
//            temp += ')';
//            search(s, res_set, temp, curr+1, open-1, s_sz, max_valid_len);
//            temp.pop_back();
//        }
//        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len);
//    }
//}
//
//vector<string> removeInvalidParentheses(string s) {
//    vector<string> res;
//    int sz = s.length();
//    unordered_set<string> res_set;
//    string temp = "";
//    int max_valid_len = 0;
//    search(s, res_set, temp, 0, 0, sz, max_valid_len);
//    for(string a:res_set) res.push_back(a);
//    return res;
//}

long get_time(){
    namespace sc = std::chrono;
    auto time = sc::system_clock::now(); // get the current time
    auto since_epoch = time.time_since_epoch(); // get the duration since epoch
    // I don't know what system_clock returns
    // I think it's uint64_t nanoseconds since epoch
    // Either way this duration_cast will do the right thing
    auto millis = sc::duration_cast<sc::milliseconds>(since_epoch);
    long now = millis.count(); // just like java (new Date()).getTime();
    return now;
}

bool is_valid(string& s){
    int open = 0;
    for(int i=0; i<s.length(); i++){
        if(open<0) return false;
        if(s[i] == '(') open++;
        else if(s[i] == ')') open--;
    }
    return open == 0;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    queue<string> q;
    unordered_set<string> visited;
    q.push(s);
    bool found = false;
    while(!q.empty()){
        string temp = q.front();
        q.pop();
        if(is_valid(temp)){
            res.push_back(temp);
            found = true;
        }
        if(found) continue;
        int open = 0;
        for(int i=0; i<temp.length(); i++){
            if(temp[i] != '(' && temp[i] != ')') continue;
            if(i>0 && temp[i]==temp[i-1]){
                if(temp[i] == '(') open++;
                else open--;
                continue;
            }
            string temp_n = temp.substr(0, i) + temp.substr(i+1, temp.length()-i-1);
            if(visited.find(temp_n) == visited.end()){
                q.push(temp_n);
                visited.insert(temp_n);
                if(open ==0 && temp[i]==')') break;
            }
            if(temp[i] == '(') open++;
            else open--;
        }
    }
    return res;
}

int main(){
//    vector<string> res = removeInvalidParentheses("()())()");
//    vector<string> res = removeInvalidParentheses("(a)())()");
//    vector<string> res = removeInvalidParentheses(")()");
//    vector<string> res = removeInvalidParentheses("(");
//    vector<string> res = removeInvalidParentheses(")");
    vector<string> res = removeInvalidParentheses("(()()))q(l)()o)(z");
    cout<<res.size()<<endl;
    for(string temp:res){
        cout<<temp<<endl;
    }
    return 0;
}