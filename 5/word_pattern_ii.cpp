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

bool check(string& str, int i, int a, int b){
    //cout<<"checking: "<<str.substr(a, b-a+1)<<" "<<str.substr(i, b-a+1)<<endl;
    for(int curr = 0; curr+a<=b; curr++){
        if(str[curr+i] != str[curr+a]) return false;
    }
    return true;
}

bool search(string& pattern, string& str, int p_sz, int s_sz, int p_curr, int s_curr, unordered_map<char,pair<int,int> >& m, unordered_map<string, char>& n, char& cause){
    //cout<<p_curr<<" "<<s_curr<<endl;
    if(s_curr == s_sz){
        if(p_curr == p_sz) return true;
        return false;
    }
    if(p_curr == p_sz) return false;
    if(m.find(pattern[p_curr]) != m.end()){
        pair<int,int> temp = m[pattern[p_curr]];
        if(check(str, s_curr, temp.first, temp.second)){
            //cout<<"checking return true"<<endl;
            bool res = search(pattern, str, p_sz, s_sz, p_curr+1, s_curr+(temp.second-temp.first)+1, m, n, cause);
            if(res) return true;
        }
        else{
            cause = pattern[p_curr];
            return false;
        };
    }
    else{
        for(int i=s_curr; i<s_sz; i++){
            string temp = str.substr(s_curr, i-s_curr+1);
            //cout<<pattern[p_curr]<<" "<<temp<<endl;
            if(n.find(temp) != n.end() && n[temp] != pattern[p_curr]) continue;
            m[pattern[p_curr]] = make_pair(s_curr, i);
            n[temp] = pattern[p_curr];
            char cause = ' ';
            bool res = search(pattern, str, p_sz, s_sz, p_curr+1, i+1, m, n, cause);
            if(res) return true;
            m.erase(m.find(pattern[p_curr]));
            n.erase(n.find(temp));
            if(cause == ' ' || cause == pattern[p_curr]) continue;
            else{
                break;
            }
        } 
    }
    return false;
}

bool wordPatternMatch(string pattern, string str) {
    int p_sz = pattern.length(), s_sz = str.length();
    unordered_map<char,pair<int,int> > m;
    unordered_map<string,char> n;
    char cause = ' ';
    return search(pattern, str, p_sz, s_sz, 0, 0, m, n, cause);
}

int main(){
    cout<<wordPatternMatch("abba", "dogcatcatdog")<<endl;
    cout<<wordPatternMatch("abab", "redblueredblue")<<endl;
    cout<<wordPatternMatch("aaaa", "asdasdasdasd")<<endl;
    cout<<wordPatternMatch("aabb", "xyzabcxzyabc")<<endl;
    return 0;
}