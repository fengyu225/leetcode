/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

#include "header.h"

//string simplifyPath(string path) {
//    int sz = path.length();
//    string res = "";
//    stack<string> s;
//    int curr = 0;
//    string temp = "";
//    while(curr<sz){
//        if(path[curr] == '/' && temp.length()>0){
//            if(temp != "." && temp != "..") s.push(temp);
//            else if(temp == ".."){
//                if(!s.empty()) s.pop();
//            }
//            temp = "";
//        }
//        else if(path[curr] != '/'){
//            temp += path[curr];
//        }
//        curr++;
//    }
//    while(!s.empty()){
//        string temp = s.top();
//        res += "/"+temp+res;
//        s.pop();
//    }
//    return res.empty()?"/":res;
//}

string simplifyPath(string path) {
    string temp, res;
    stack<string> st;
    stringstream ss(path);
    while(getline(ss, temp, '/')){
        if(temp.length() == 0 || temp == ".") continue;
        if(temp == ".." && !st.empty()) st.pop();
        else if(temp != "..") st.push(temp);
    }
    while(!st.empty()){
        res = "/"+st.top()+res;
        st.pop();
    }
    return res.empty()? "/":res;
}

int main(){
    cout<<simplifyPath("/a/./b/../../c/")<<endl;
    cout<<simplifyPath("/")<<endl;
    cout<<simplifyPath("/a//b/../../c/")<<endl;
    return 0;
}