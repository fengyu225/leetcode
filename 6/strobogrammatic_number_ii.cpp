/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

#include "header.h"

vector<string> search(int n, int x){
    vector<string> res;
    if(n == 0) return res;
    if(n == 1){
        res.push_back("0");
        res.push_back("1");
        res.push_back("8");
    }
    else if(n == 2){
        if(n != x) res.push_back("00");
        res.push_back("11");
        res.push_back("88");
        res.push_back("69");
        res.push_back("96");
    }
    else{
        vector<string> temp = search(n-2, x);
        for(auto s:temp){
            if(n!=x) res.push_back("0"+s+"0");
            res.push_back("1"+s+"1");
            res.push_back("8"+s+"8");
            res.push_back("6"+s+"9");
            res.push_back("9"+s+"6");
        } 
    }
    return res; 
}

vector<string> findStrobogrammatic(int n) {
    return search(n, n);
}

int main(){
    vector<string> res = findStrobogrammatic(3);
    sort(res.begin(), res.end());
    for(auto s:res) cout<<s<<" ";
    cout<<endl;
    return 0;
}