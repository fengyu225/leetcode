/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

#include "header.h"

/* short c++ code from leetcode discussion
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}
*/

string simplifyPath(string path) {
    stack<string> s;
    int sz = path.length(), curr=0;
    string temp = "", res="";
    while(curr<=sz){
        if(curr == sz || path[curr] == '/'){
            if(temp.length()>0){
                if(temp == ".."){
                    if(!s.empty()) s.pop();
                }
                else if(temp != ".") s.push(temp); 
                temp = "";
            }
        }
        else temp+=path[curr];
        curr++;
    }
    if(s.empty()) return "/";
    while(!s.empty()){
        res.insert(0,s.top());
        res.insert(0,"/");
        s.pop();
    }
    return res;
}

int main(){
//    cout<<simplifyPath("/home/")<<endl;
    cout<<simplifyPath("/abc/.../")<<endl;
//    cout<<simplifyPath("//")<<endl;
//    cout<<simplifyPath("/a/./b/../../c/")<<endl;
    return 0;
}