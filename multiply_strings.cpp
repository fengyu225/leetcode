#include "header.h"

string add(string num1, string num2){
    if(num1.size() == 0 || num1 == "0") return num2;
    if(num2.size() == 0 || num2 == "0") return num1;
    int carry = 0;
    string res;
    int l = num1.size()-1, r = num2.size()-1;
    while(l>=0 && r>=0){
        int x = (num1[l]-'0')+(num2[r]-'0')+carry;
        res = char((x%10)+'0')+res;
        carry = x/10;
        l--;
        r--;
    }
    string s = l>=0?num1:num2;
    int idx = l>=0?l:r;
    if(l<0 && r<0 && carry>0)
        return char(carry+'0')+res;
    while(carry>0 && idx>=0){
        int x = (s[idx]-'0')+carry;
        res = char((x%10)+'0')+res;
        carry = x/10;
        idx--;
    }
    if(carry) return char(carry+'0')+res;
    if(idx>=0) return s.substr(0,idx+1)+res;
    return res;
}

string mul(string num1, char c){
    if(c == '0') return "0";
    int carry = 0;
    string res;
    for(int i=num1.size()-1; i>=0; i--){
        int x = (c-'0')*(num1[i]-'0')+carry;
        res = char((x%10)+'0')+res;
        carry = x/10;
    }
    if(carry)
        res = char(carry+'0')+res;
    return res;
}

string multiply(string num1, string num2){
    if(num1.size() == 0 || num2.size() == 0 || num1.compare("0")==0 || num2.compare("0") == 0)
        return "0";
    string res;
    for(int j = num2.size()-1; j>=0; j--){
        string x = num1;
        for(int i=0; i<num2.size()-1-j; i++)
            x += "0";
        string m = mul(x,num2[j]);
        res = add(res,m);
    }
    return res;
}

int main(){
    string res = multiply("7967", "7067");
    //string res = add("12345678987654321", "98765432123456789");
    //string res = mul("12345678987654321", '2');
    printf("%s\n", res.c_str());
    return 0;
}
