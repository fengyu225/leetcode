#include "header.h"

string addBinary(string a, string b) {
    int a_idx = a.size()-1;
    int b_idx = b.size()-1;
    int carry = 0;
    string res;
    while(a_idx>=0 || b_idx>=0){
        int a_val = a_idx>=0?a[a_idx]-'0':0;
        int b_val = b_idx>=0?b[b_idx]-'0':0;
        int temp = a_val+b_val+carry;
        res = (char)((temp%2)+'0') + res;
        a_idx--;
        b_idx--;
        carry = temp/2;
    }
    if(carry)
        res = (char)(carry+'0')+res;
    return res;
}

int main(){
    string a("11");
    string b("1");
    string res = addBinary(a,b);
    printf("%s\n", res.c_str());
    return 0;
}
