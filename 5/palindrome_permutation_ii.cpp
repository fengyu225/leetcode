/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/

#include "header.h"

void swap(string& s, int l, int r){
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
}

bool check(string& even, int curr, int i){
    for(int j=curr; j<i; j++) if(even[j] == even[i]) return false;
    return true;
}

void search(string& even, int curr, char& odd_char, vector<string>& res){
    if(curr == even.length()){
        string temp = even;
        reverse(temp.begin(), temp.end());
        if(odd_char != ' ') res.push_back(even+odd_char+temp);
        else res.push_back(even+temp);
        return;
    }
    for(int i=curr; i<even.length(); i++){
        if(check(even, curr, i)){
            swap(even, curr, i);
            search(even, curr+1, odd_char, res);
            swap(even, curr, i);
        }
    }
}

vector<string> generatePalindromes(string s) {
    int sz = s.length();
    vector<string> res;
    unordered_map<char, int> m;
    for(char c:s) m[c]++;
    int odd_count = 0;
    char odd_char = ' ';
    string even = "";
    for(auto i:m){
        if(i.second%2 == 1){
            odd_count++;
            odd_char = i.first;
        }
        else{
            int c = i.second/2;
            for(int j=0; j<c; j++) even+=i.first;
        }
    }
    if(odd_count>=2) return res;
    if(m[odd_char] != 1){
        int c = m[odd_char]/2;
        for(int i=0; i<c; i++) even+=odd_char;
    }
    sort(even.begin(), even.end());
    search(even, 0, odd_char, res);
    return res;
}

int main(){
    //vector<string> res = generatePalindromes("aabb");
    //vector<string> res = generatePalindromes("abc");
    vector<string> res = generatePalindromes("aaaaaa");
    for(string s:res) cout<<s<<" ";
    cout<<endl;
    return 0;
}