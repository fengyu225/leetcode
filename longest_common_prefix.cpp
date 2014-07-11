#include "header.h"

string longestCommonPrefix(vector<string> &strs) {
    string res;
    if(strs.size()==0) return res;
    if(strs.size()==1) return strs[0];
    int i=0;
    while(1){
        char c=strs[0][i];
        for(int j=1;j<strs.size();j++){
            if(i==strs[j].size() || strs[j][i] != c)
                return res;
        }
        res+=c;
        i++;
        c=strs[0][i];
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
