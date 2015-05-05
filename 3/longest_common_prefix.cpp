#include "header.h"

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

string longestCommonPrefix(vector<string>& strs, int l, int r){
    if(l == r) return strs[l];
    int m = (l+r)/2;
    string l_prefix = longestCommonPrefix(strs, l, m);
    string r_prefix = longestCommonPrefix(strs, m+1, r);
    return lcp(l_prefix, r_prefix);
}

string longestCommonPrefix(vector<string> &strs) {
    if(strs.size() == 0) return "";
    if(strs.size() == 1) return strs[0];
    return longestCommonPrefix(strs,0,strs.size()-1);
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
