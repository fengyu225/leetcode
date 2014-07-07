#include "header.h"

void combine(string digits, int n, string map[], vector<string>& v, string& s){
    if(n == digits.size()){
        v.push_back(s);
        return;
    }
        for(int j=0;j<map[digits[n]-'0'].size();j++){
            s += map[digits[n]-'0'][j];
            combine(digits,n+1,map,v,s);
            s = s.substr(0,s.size()-1);
        }
}

vector<string> letterCombinations(string digits) {
    string map[] = {
        "", "1", "abc", "def", 
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string> res;
    string x;
    combine(digits,0,map,res,x);
    return res;
}

int main(){
    vector<string> res = letterCombinations("23");
    for(int i=0; i<res.size(); i++)
        printf("%s ", res[i].c_str());
    printf("\n");
    return 0;
}
