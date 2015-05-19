#include "header.h"

string longestCommonPrefix(vector<string>& strs) {
    int sz = strs.size();
    if(sz == 0) return "";
    if(sz == 1) return strs[0];
    string res = "";
    bool end = false;
    for(int i=0; i<=strs[0].size(); i++){
        if(i == strs[0].size()) end = true;
        for(int j=1;j<sz;j++){
            bool x = 
                (end && strs[j].size()>i) ||
                (!end && i>=strs[j].size()) ||
                (!end && i<strs[j].size() && strs[j][i] != strs[0][i]);
            if(x) return res;
        }
        if(!end) res += strs[0][i];
    }
    return res;
}

string lcp(string a, string b){
    string res;
    if(a.size() == 0 || b.size() == 0) return res;
    int a_idx = 0,b_idx = 0;
    while(a_idx<a.size() && b_idx<b.size()){
            if(a[a_idx] == b[b_idx]){
                        res += a[a_idx];
                        a_idx++;
                        b_idx++;
                    }
            else
                break;
        }
    return res;
}

int main(){
    string s0("abce");
    string s1("abcd");
    string s2("abde");
    string s3("abcf");
    vector<string> v;
    v.push_back(s0);
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    string res = longestCommonPrefix(v);
    printf("%s\n", res.c_str());
    return 0;
}
