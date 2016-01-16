/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

#include "header.h"

bool search(string& pattern, string& str, int p_sz, int s_sz, int p_curr, int s_curr, unordered_map<char,string>& m, unordered_map<string,char>& n){
    cout<<"pattern pos: "<<p_curr<<", str pos: "<<s_curr<<endl;
    if(s_curr == s_sz && p_curr == p_sz) return true;
    if(p_sz-p_curr>s_sz-s_curr || p_curr == p_sz) return false;
    if(m.find(pattern[p_curr]) != m.end()){
        string temp = m[pattern[p_curr]];
        cout<<"tring to advance: "<<temp<<" to match: "<<str.substr(s_curr, temp.length())<<endl;
        if(str.substr(s_curr, temp.length()) == temp){
            cout<<"advance success"<<endl;
            bool res = search(pattern, str, p_sz, s_sz, p_curr+1, s_curr+temp.length(), m, n);
            if(res) return true;
        }
        else{
            cout<<"advance fail, cause is: "<<pattern[p_curr]<<endl;
            return false;
        };
    }
    else{
        for(int i=s_curr; i<s_sz; i++){
            string temp = str.substr(s_curr, i-s_curr+1);
            if(n.find(temp) != n.end() && n[temp] != pattern[p_curr]) continue;
            m[pattern[p_curr]] = temp;
            n[temp] = pattern[p_curr];
            cout<<"setting map: "<<pattern[p_curr]<<"->"<<temp<<endl;
            bool res = search(pattern, str, p_sz, s_sz, p_curr+1, i+1, m, n);
            if(res) return true;
            m.erase(m.find(pattern[p_curr]));
            n.erase(n.find(temp));
        } 
    }
    return false;
}

bool wordPatternMatch(string pattern, string str) {
    int p_sz = pattern.length(), s_sz = str.length();
    unordered_map<char,string> m;
    unordered_map<string,char> n;
    return search(pattern, str, p_sz, s_sz, 0, 0, m, n);
}

int main(){
    cout<<wordPatternMatch("abab", "abbbabbb")<<endl;
//    cout<<wordPatternMatch("abba", "dogcatcatdog")<<endl;
//    cout<<wordPatternMatch("abab", "redblueredblue")<<endl;
//    cout<<wordPatternMatch("aaaa", "asdasdasdasd")<<endl;
//    cout<<wordPatternMatch("aabb", "xyzabcxzyabc")<<endl;
    return 0;
}