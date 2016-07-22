/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include "header.h"

bool isValid(string s) {
    int sz = s.length();
    if(sz == 0) return true;
    if(sz == 1) return false;
    stack<char> stack;
    for(int i=0; i<sz; i++){
        char curr = s[i];
        if(curr == '(' || curr=='{' || curr=='[') stack.push(curr);
        else{
            if(stack.empty()) return false;
            char t = stack.top();
            if((curr == ')' && t=='(') || (curr=='}' && t=='{') || (curr==']' && t=='[')){
                stack.pop();
            }
            else return false;
        }
    }
    return stack.empty();
}

int main(){
    printf("%s\n", isValid("()([]{})")?"true":"false");
    printf("%s\n", isValid("([)]")?"true":"false");
    return 0;
}
