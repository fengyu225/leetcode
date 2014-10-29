#include "header.h"

string expand(string s, int i, int j){
    while(i>=0 && j<=s.size()-1 && s[i] == s[j]){
        i--;
        j++;
    }
    return s.substr(i+1,j-1-i);
}

string longestPalindrome(string s) {
    if(s.size() == 0) return "";
    string res = s.substr(0,1);
    for(int i=0; i<s.size(); i++){
        string x = expand(s,i,i);
        if(x.size()>res.size())
            res = x;
    }
    for(int i=0; i<s.size()-1; i++){
        string x = expand(s,i,i+1);
        if(x.size()>res.size())
            res = x;
    }
    return res;
}

int main(){
    string s0 = longestPalindrome("abacdfgdcaba");
    printf("%s\n", s0.c_str());
    return 0;
}
