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
//    //naive dfs
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

void search(string& s, unordered_set<string>& res_set, string& temp, int curr, int open, int s_sz, int& max_valid_len, bool left_deleted){
    // dfs
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
        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len, left_deleted);
        temp.pop_back();
        return;
    }
    if(s[curr] == '('){
        temp += "(";
        search(s, res_set, temp, curr+1, open+1, s_sz, max_valid_len, left_deleted);
        temp.pop_back();
        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len, true);
    }
    else{
        if(!(s[curr] == ')' && open==0)){
            temp += ')';
            search(s, res_set, temp, curr+1, open-1, s_sz, max_valid_len, left_deleted);
            temp.pop_back();
        }
        if(!left_deleted){
            search(s, res_set, temp, curr+1, open, s_sz, max_valid_len, left_deleted);
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    int sz = s.length();
    unordered_set<string> res_set;
    string temp = "";
    int max_valid_len = 0;
    search(s, res_set, temp, 0, 0, sz, max_valid_len, false);
    for(string a:res_set) res.push_back(a);
    return res;
}

//bool is_valid(string& s){
//    int open = 0;
//    for(int i=0; i<s.length(); i++){
//        if(open<0) return false;
//        if(s[i] == '(') open++;
//        else if(s[i] == ')') open--;
//    }
//    return open == 0;
//}
//
//class Node{
//    public:
//        Node(string s, int last_index):s(s),last_index(last_index),met_left(false){}
//        Node(string s, int last_index, bool met_left):s(s),last_index(last_index),met_left(met_left){}
//        string s;
//        int last_index;
//        bool met_left;
//};

/*
The naive BFS solution is quite simple to implement. To speed up we can use a Set to record all the strings generated and avoid revisit. But a better and faster solution is to avoid generate duplicate strings all together.

The first observation is when we want to remove a ')' or '(' from several consecutive ones we only remove the first one, because remove any one the result will be the same. For example

"())" ---> "()"
only remove the first one of '))'
The second observation is when we remove a character it must behind it's parent removal position. For example

we need remove 2 from "(())(("
we want to remove positions combination i,j with no duplicate
so we let i < j then it will not generate duplicate combinations
in practice, we record the position i and put it in to queue
which is then polled out and used as the starting point of the next removal
A third observation is if the previous step we removed a "(", we should never remove a ")" in the following steps. This is obvious since otherwise we could just save these two removals and still be valid with less removals. With this observation all the possible removals will be something like this

")))))))))((((((((("
All the removed characters forming a string with consecutive left bracket followed by consecutive right bracket.

By applying these restrictions, we can avoid generate duplicate strings and the need of a set which saves a lot of space.

Ultimately we can further improve the algorithm to eliminate isValid calls. To do this we need to remove and only remove those characters that would lead us to valid strings. This needs some preprocess and can reduce the time to around 3ms.
*/

//vector<string> removeInvalidParentheses(string s) {
//    vector<string> res;
//    queue<Node*> q_curr, q_next;
//    queue<Node*> qs[2] = {q_curr, q_next};
//    int curr = 0;
//    bool found = false;
//    qs[curr%2].push(new Node(s, 0));
//    unordered_set<string> visited;
//    while(!qs[curr%2].empty()){
//        Node* temp = qs[curr%2].front();
//        qs[curr%2].pop();
//        if(is_valid(temp->s)){
//            res.push_back(temp->s);
//            found = true;
//        }
//        if(found) continue;
//        int temp_sz = temp->s.length();
//        for(int i=temp->last_index; i<temp_sz; i++){
//            if(temp->s[i] != '(' && temp->s[i] != ')') continue;
//            if(temp->met_left && temp->s[i] == ')') continue;
//            if(!(i>temp->last_index && temp->s[i] == temp->s[i-1])){
//                string temp_n = temp->s.substr(0, i) + temp->s.substr(i+1, temp_sz-i-1);
//                qs[(curr+1)%2].push(new Node(temp_n, i, temp->s[i] == '('));
//            }
//        }
//        if(qs[curr%2].empty()) curr++;
//    }
//    return res;
//}

//vector<string> removeInvalidParentheses(string s) {
//    //naive bfs
//    vector<string> res;
//    queue<string> q;
//    unordered_set<string> visited;
//    q.push(s);
//    bool found = false;
//    while(!q.empty()){
//        string temp = q.front();
//        q.pop();
//        if(is_valid(temp)){
//            res.push_back(temp);
//            found = true;
//        }
//        if(found) continue;
//        int open = 0;
//        for(int i=0; i<temp.length(); i++){
//            if(temp[i] != '(' && temp[i] != ')') continue;
//            if(i>0 && temp[i]==temp[i-1]){
//                if(temp[i] == '(') open++;
//                else open--;
//                continue;
//            }
//            string temp_n = temp.substr(0, i) + temp.substr(i+1, temp.length()-i-1);
//            if(visited.find(temp_n) == visited.end()){
//                q.push(temp_n);
//                visited.insert(temp_n);
//                if(open ==0 && temp[i]==')') break;
//            }
//            if(temp[i] == '(') open++;
//            else open--;
//        }
//    }
//    return res;
//}

int main(){
//    vector<string> res = removeInvalidParentheses("()())()");
//    vector<string> res = removeInvalidParentheses("(a)())()");
//    vector<string> res = removeInvalidParentheses(")()");
//    vector<string> res = removeInvalidParentheses("(");
//    vector<string> res = removeInvalidParentheses(")");
//    vector<string> res = removeInvalidParentheses("(()()))q(l)()o)(z");
    string x = "";
    for(int i=0; i<100; i++) x+="(";
    for(int i=0; i<99; i++) x+=")";
    vector<string> res = removeInvalidParentheses(x);
    cout<<res.size()<<endl;
    for(string temp:res){
        cout<<temp<<endl;
    }
    return 0;
}