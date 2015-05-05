#include "header.h"

vector<string> anagrams(vector<string> &strs) {
}

int main(){
    string s0("tea");
    string s1("and");
    string s2("ate");
    string s3("eat");
    string s4("den");
    vector<string> strs;
    strs.push_back(s0);
    strs.push_back(s1);
    strs.push_back(s2);
    strs.push_back(s3);
    strs.push_back(s4);
    vector<string> res = anagrams(strs);
    for(int i=0; i<res.size(); i++)
        printf("%s ", res[i].c_str());
    printf("\n");
    return 0;
}
