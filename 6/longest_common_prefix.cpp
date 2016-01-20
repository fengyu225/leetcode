#include "header.h"

string longestCommonPrefix(vector<string>& strs) {
    int sz = strs.size();
    if(sz == 0) return "";
    if(sz == 1) return strs[0];
    string res = "";
    for(int i=0; i<strs[0].size(); i++){
        res.push_back(strs[0][i]);
        for(int j=1; j<sz; j++){
            if(i == strs[j].size() || strs[j][i] != strs[0][i]){
                res.pop_back();
                return res;
            }
        }
    }
    return res;
}

int main(){
//    string s0("abce");
//    string s1("abcd");
//    string s2("abde");
//    string s3("abcf");
//    vector<string> v;
//    v.push_back(s0);
//    v.push_back(s1);
//    v.push_back(s2);
//    v.push_back(s3);
    vector<string> v = {
        "ab",
        ""
    };
    string res = longestCommonPrefix(v);
    printf("%s\n", res.c_str());
    return 0;
}
