#include "header.h"

int longestValidParentheses(string s) {
    if(s.size()<=1 || s.size()%2==1) return 0;
    int m[s.size()][s.size()+1];
    for(int i=0; i<s.size(); i++){
        m[i][0] = 0;
        m[i][1] = 0;
    }
    for(int i=0; i+1<s.size(); i++) m[i][2]=s[i]=='('&&s[i+1]==')'?1:0;
    for(int i=0; i
    return m[0][s.size()];
}

int main(){
    string s0(")()())");
    printf("%d\n", longestValidParentheses(s0));
    string s1("(()");
    printf("%d\n", longestValidParentheses(s1));
    string s2("");
    printf("%d\n", longestValidParentheses(s2));
    return 0;
}
