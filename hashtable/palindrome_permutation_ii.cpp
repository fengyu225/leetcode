/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/

#include "header.h"

void swap(string& s, int i, int j){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void search(string& chars, int curr, char& odd, vector<string>& res){
    if(curr == chars.length()){
        string x = odd==-1?"":string(1,(char)odd);
        string temp = chars;
        reverse(temp.begin(), temp.end());
        res.push_back(chars+x+temp);
        return;
    }
    for(int i=curr; i<chars.length(); i++){
        if(i>curr && chars[i] == chars[curr]) continue;
        swap(chars, i, curr);
        search(chars, curr+1, odd, res);
        swap(chars, i, curr);
    }
}

vector<string> generatePalindromes(string s) {
    int s_len = s.length();    
    vector<string> res;
    int arr[256] = {0};
    for(char c:s) arr[c]++;
    string chars = "";
    char odd=-1;
    for(int i=0; i<256; i++){
        if(arr[i] == 0) continue;
        if(arr[i]&1){
            if(odd!=-1) return res;
            odd = (char)i;
        }
        else chars+=string(arr[i]/2, (char)i); 
    }
    if(odd != -1) chars += string((arr[odd]-1)/2, odd);
//    cout<<chars<<" "<<odd<<endl;
    search(chars, 0, odd, res);
    return res;
}

int main(){
    //vector<string> res = generatePalindromes("aabb");
    //vector<string> res = generatePalindromes("abc");
//    print_vector<string>(generatePalindromes("aaaaaa"));
//    print_vector<string>(generatePalindromes("aabb"));
//    print_vector<string>(generatePalindromes("abd"));
    print_vector<string>(generatePalindromes("aaa"));
    return 0;
}