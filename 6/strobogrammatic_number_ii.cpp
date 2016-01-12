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

vector<string> findStrobogrammatic(int n, int curr_l){
    if(n == 0) return vector<string>();
    if(n == 1){
        vector<string> res = {"1", "8"};
        return res;
    }
}

vector<string> findStrobogrammatic(int n) {
    return findStrobogrammatic(n, n)
}

int main(){
    vector<string> res = findStrobogrammatic(3);
    sort(res.begin(), res.end());
    for(auto s:res) cout<<s<<" ";
    cout<<endl;
    return 0;
}