/*
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include "header.h"

void search(string& digits, int curr, string& s, vector<string>& res, string map[]){
    if(curr == digits.length()){
        res.push_back(s);
        return;
    }
    int curr_n = digits[curr]-'0';
    for(int i=0; i<map[curr_n].length(); i++){
        s += map[curr_n][i];
        search(digits, curr+1, s, res, map);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {    
    string map[] = {
        "", "1", "abc", "def", 
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string> res;
    if(digits.length() == 0) return res;
    string s="";
    search(digits, 0, s, res, map);
    return res; 
}

int main(){
    vector<string> res = letterCombinations("23");
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
