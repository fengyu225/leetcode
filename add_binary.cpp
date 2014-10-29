/*

 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 

*/

#include "header.h"

string addBinary(string a, string b) {
    if(a.size() == 0) return b;
    if(b.size() == 0) return a;
    string res;
    int carry = 0;
    int a_idx = a.size()-1;
    int b_idx = b.size()-1;
    while(a_idx>=0 || b_idx>=0){
        int l = a_idx>=0?a[a_idx]-'0':0;
        int r = b_idx>=0?b[b_idx]-'0':0;
        int curr = (l+r+carry)%2;
        carry = (l+r+carry)/2;
        res = to_string(curr)+res;
        a_idx--;
        b_idx--;
    }
    if(carry)
        res = to_string(carry)+res;
    return res;
}

int main(){
    string a("11");
    string b("1");
    string res = addBinary(a,b);
    printf("%s\n", res.c_str());
    return 0;
}
