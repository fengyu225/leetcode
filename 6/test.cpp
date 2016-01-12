#include "header.h"


string findKey(string s){
    string res = "";
    if(s.length() == 0) return res;
    int offset = s[0]-'a';
    for(char c:s) res.push_back((c-offset-'a')%26+'a');
    return res;
}
int main(){
    cout<<findKey("abc")<<endl;
    return 0;
}