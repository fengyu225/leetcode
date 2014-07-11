#include "header.h"

string longestCommonPrefix(vector<string> &strs) {
    string res;
    if(strs.size()==0) return res;
    if(strs.size()==1) return strs[0];

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
