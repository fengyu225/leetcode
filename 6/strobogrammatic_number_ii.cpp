/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

#include "header.h"

unordered_map<char,char> m = {
    {'0', '0'},
    {'1', '1'},
    {'6', '9'},
    {'8', '8'},
    {'9', '6'}
};

vector<string> findStrobogrammatic(int n, bool first){
    if(n == 0) return first?vector<string>():vector<string>(1,"");
    if(n == 1){
        vector<string> res = {"0", "1", "8"};
        return res;
    }
    vector<string> temp = findStrobogrammatic(n-2, false);
    vector<string> res;
    for(auto p:m){
        if(first && p.first == '0') continue;
        for(string x:temp) res.push_back(string(1,p.first)+x+string(1,p.second)); 
    }
    return res;
}

vector<string> findStrobogrammatic(int n) {
    return findStrobogrammatic(n, true);
}

int main(){
    vector<string> res = findStrobogrammatic(1);
    sort(res.begin(), res.end());
    for(auto s:res) cout<<s<<" ";
    cout<<endl;
    return 0;
}