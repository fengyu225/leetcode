/*
" I love    this game    !    " => " I love this game ! "
*/

#include "header.h"

string remove_multi_spaces(string s){
    string res = s;
    int tail = -1;
    int curr = 0, sz = s.length();
    while(curr<sz){
        if(tail>=0 && res[tail] == s[curr] && s[curr] == ' ') curr++;
        else res[++tail] = s[curr++];
    }
    return res.substr(0, tail+1);
}

int main(){
    cout<<"|"<<remove_multi_spaces(" I love    this game    !    ")<<"|"<<endl;
}