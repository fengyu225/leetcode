#include "header.h"

using std::to_string;

string count(string s){
    int c=0;
    int l=0,r=0;
    string res;
    while(r<s.size()){
        if(s[l] == s[r]){
            c++;
            r++;
            continue;
        }
        res = res+to_string(c)+s.substr(l,1);
        l = r;
        c=0;
    }
    res = res+to_string(c)+s.substr(l,1);
    return res;
}

string countAndSay(int n) {
    if(n==1) return "1";
    string last("1");
    for(int i=2; i<=n; i++)
        last = count(last);
    return last;
}

int main(){
    string res = countAndSay(5);
    printf("%s\n", res.c_str());
    return 0;
}
