/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add operators +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

// 3:24
#include "header.h"

void search(string& num, int l, int r, unordered_map<string,int>& m){
    if(l>r) return;
    if(l == r){
        m[num.substr(l, 1)] = num[l]-'0';
        return;
    }
    for(int i=l; i<r; i++){
        unordered_map<string,int> l_m;
        unordered_map<string,int> r_m;
        search(num, l, i, l_m);
        search(num, i+1, r, r_m);
        for(auto l_i:l_m){
            for(auto r_i:r_m){
                m[l_i.first+"+"+r_i.first] = l_i.second+r_i.second;
                m[l_i.first+"-"+r_i.first] = l_i.second-r_i.second;
                m[l_i.first+"*"+r_i.first] = l_i.second*r_i.second;
            }
        }
    }
}

vector<string> addOperators(string num, int target) {
    int sz = num.length();
    if(sz == 1) return num[0]-'0' == target?vector<string>(1, num):vector<string>(); 
    unordered_map<string,int> m;
    search(num, 0, sz-1, m);
    vector<string> res;
    for(auto i:m) if(i.second == target) res.push_back(i.first);
    return res;
}

int main(){
    //vector<string> res = addOperators("123", 6);
    vector<string> res = addOperators("00", 0);
    print_vector<string>(res);
    return 0;
}