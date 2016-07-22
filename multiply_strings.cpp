/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include "header.h"

string add(string num1, string num2){
    int sz1 = num1.size();
    int sz2 = num2.size();
    if(sz1 == 0) return num2;
    if(sz2 == 0) return num1;
    string res = "";
    int curr1 = sz1-1, curr2=sz2-1;
    int carry = 0;
    while(curr1>=0 || curr2>=0){
        int a = curr1>=0?num1[curr1]-'0':0;
        int b = curr2>=0?num2[curr2]-'0':0;
        res = to_string((a+b+carry)%10)+res;
        carry = (a+b+carry)/10;
        curr1 -= 1;
        curr2 -= 1;
    }
    if(carry)
        res = to_string(carry)+res;
    return res;
}

string multiply(string num1, string num2){
    int sz1 = num1.size();
    int sz2 = num2.size();
    string res = "";
    int carry = 0,r=0;
    for(int i=sz2-1; i>=0; i--){
        string temp = "";
        carry = 0;
        r = 0;
        for(int j=sz1-1; j>=0; j--){
            int a = num2[i] - '0';
            int b = num1[j] - '0';
            r = a*b+carry;
            temp = to_string(r%10)+temp;
            carry = r/10;
        }
        if(carry) temp = to_string(carry)+temp;
        for(int x=0; x<sz2-1-i; x++)
            temp += to_string(0);
        res = add(res,temp);
    }
    int x = 0;
    while(x<res.size()){
        if(res[x] != '0') break;
        x++;
    }
    return x==res.size()?"0":res.substr(x,res.size()-x);
}


int main(){
    string res = multiply("7967", "7067");
    //string res = add("12345678987654321", "98765432123456789");
    //string res = mul("12345678987654321", '2');
    printf("%s\n", res.c_str());
    return 0;
}
