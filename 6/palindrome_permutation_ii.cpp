/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/

#include "header.h"

void search(string& temp, int curr, char c, vector<string>& res){
    if(curr == temp.length()){
        string orig_t = temp;
        string x = temp;
        reverse(x.begin(), x.end());
        if(c != -1) temp.push_back(c);
        temp += x;
        res.push_back(temp);
        temp = orig_t;
        return;
    }
    int sz = temp.length();
    for(int i=curr; i<sz; i++){
        if(i>curr && temp[i] == temp[i-1]) continue;
        swap(temp[curr], temp[i]);
        search(temp, curr+1, c, res);
        swap(temp[curr], temp[i]);
    }
}

vector<string> generatePalindromes(string s) {
    vector<string> res;    
    unordered_map<char,int> m;
    for(char c:s) m[c]++;
    int cnt = 0;
    string temp = "";
    char c = -1;
    for(auto p:m){
        if(p.second%2 == 1){
            cnt++;
            c = p.first;
            if(p.second>1) temp += string(p.second/2, p.first);
        }
        else temp += string(p.second/2, p.first);
    }
    if(cnt > 1) return res;
    sort(temp.begin(), temp.end());
    search(temp, 0, c, res);
    return res;
}

int main(){
    //vector<string> res = generatePalindromes("aabb");
    //vector<string> res = generatePalindromes("abc");
    //print_vector<string>(generatePalindromes("aaaaaa"));
//    print_vector<string>(generatePalindromes("aabb"));
//    print_vector<string>(generatePalindromes("abd"));
    print_vector<string>(generatePalindromes("abcabc"));
    return 0;
}