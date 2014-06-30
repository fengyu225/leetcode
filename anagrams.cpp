#include "header.h"

string sort_str(string& s){
    int m[26]={0};
    for(int i=0; i<s.size(); i++)
        m[s[i]-'a']++;
    string res = "";
    for(int i=0; i<26; i++){
        if(m[i]>0){
            for(int j=0; j<m[i]; j++)
                res += (char)(i+'a');
        }
    }
    return res;
}

vector<string> anagrams(vector<string> &strs) {
    vector<string> res;
    unordered_map<string, vector<string> > m;
    for(int i=0; i<strs.size(); i++){
        string s = sort_str(strs[i]);
        if(m.find(s) == m.end()){
            vector<string> v;
            m[s] = v;
        }
        m[s].push_back(strs[i]);
    }
    for(auto iter = m.begin();
            iter!=m.end(); iter++){
        if(iter->second.size()>1){
            for(int i=0; i<iter->second.size(); i++)
                res.push_back((iter->second)[i]);
        }
    }
    return res;
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
