/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

#include "header.h"

//string removeDuplicateLetters(string s) {
//    // https://leetcode.com/discuss/73761/a-short-o-n-recursive-greedy-solution
//    int sz = s.length();
//    if(sz == 0) return "";
//    vector<int> count(26, 0);
//    for(int i=0; i<sz; i++) count[s[i]-'a']++;
//    int pos = 0;
//    for(int i=0; i<sz; i++){
//        if(s[i]<s[pos]) pos = i;
//        count[s[i]-'a']--;
//        if(count[s[i]-'a'] == 0) break;
//    }
//    char temp = s[pos];
//    s = s.substr(pos+1, sz-pos-1);
//    s.erase(remove(s.begin(), s.end(), temp), s.end());
//    return temp+removeDuplicateLetters(s);
//}

//    string removeDuplicateLetters(string s) {
//        unordered_map<char, int> cnts;
//        string ret;
//        stack<char> stk;
//        vector<bool> isVisited(26, false);
//        for (char each : s) cnts[each] ++;
//        for (int i = 0; i < s.size(); cnts[s[i]] --, ++ i) {
//            if (isVisited[s[i] - 'a'] || (!stk.empty() && stk.top() == s[i])) continue;
//            while (!stk.empty() && stk.top() > s[i] && cnts[stk.top()] > 0) {
//                isVisited[stk.top() - 'a'] = false;
//                stk.pop();
//            }
//            stk.push(s[i]);
//            isVisited[s[i] - 'a'] = true;
//        }
//        while (!stk.empty()) {
//            ret.push_back(stk.top());
//            stk.pop();
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }

string removeDuplicateLetters(string s) {
    int sz = s.length();
    if(sz < 2) return s;
    stack<int> st;
    string res = "";
    vector<int> count(26, 0);
    vector<bool> in_stack(26, false);
    for(char c:s) count[c-'a']++;
    for(int i=0; i<sz; count[s[i]-'a']--, i++){
        if(in_stack[s[i]-'a']) continue;
        while(!st.empty() && st.top()>s[i] && count[st.top()-'a']>0){
            in_stack[st.top()-'a'] = false;
            st.pop();
        }
        st.push(s[i]);
        in_stack[s[i]-'a']=true;
    } 
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
//    cout<<removeDuplicateLetters("cbacdcbc")<<endl;
    //cout<<removeDuplicateLetters("yioccqiorhtoslwlvfgzycahonecugtatbyphpuunwvaalcpndabyldkdtzfjlgwqk")<<endl;
    cout<<removeDuplicateLetters("baa")<<endl;
    return 0;
}