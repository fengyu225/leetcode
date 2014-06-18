#include "header.h"

int longestValidParentheses(string s) {
    if(s.size()<=1) return 0;
    int arr[s.size()];
    int max=0;
    for(int i=0;i<s.size();i++) arr[i]=0;
    for(int i=s.size()-2;i>=0;i--){
        if(s[i] == ')') continue;
        int j=i+arr[i+1]+1;
        if(j<s.size() && s[j]==')'){
            arr[i]=arr[i+1]+2;
            int k=(j+1<s.size())?arr[j+1]:0;
            arr[i]+=k;
            max=max<arr[i]?arr[i]:max;
        }
    }
    return max;
}

int longestValidParentheses(string s) {
    stack<int> st;
    int max = 0;
    int last = -1;
    if(s.size()<=1) return 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(')
            st.push(i);
        else{
            if(st.empty()){
                last = i;
                continue;
            }
            st.pop();
            if(st.empty())
                max = i-last>max?i-last:max;
            else
                max = i-st.top()>max?i-st.top():max;
        }
    }
    return max;
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
