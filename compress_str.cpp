#include "header.h"

string compress(string s){
    int sz = s.size();
    if(sz<2) return s;
    string res = "";
    int l = 0, r=1;
    while(r<sz){
        if(s[r] == s[l]) r++;
        else{
            res += s[l]+to_string(r-l);
            l = r++;
        }
    }
    res += s[l]+to_string(r-l);
    return res;
}

int main(){
    cout<<compress("abbbccccaaa")<<endl;
    return 0;
}