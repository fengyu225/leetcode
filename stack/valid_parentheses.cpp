/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include "header.h"

bool isValid(string s) {
    stack<char> st;
    for(char c:s){
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else{
            if(st.empty()) return false;
            char x = st.top();
            if(c == ')' && x == '(' || c == ']' && x == '[' || c == '}' && x == '{') st.pop();
            else return false;
        }
    }
    return s.empty();
}

int main(){
    cout<<isValid("()[]{}")<<endl;
    cout<<isValid("()(]{}")<<endl;
    return 0;
}