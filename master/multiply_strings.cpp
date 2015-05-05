#include "header.h"

int max(int a,int b){
    return a>b?a:b;
}

string mul(string num, char c){
    if(c=='0') return "0";
    int carry = 0;
    string result;
    for(int i=num.size()-1; i>=0; i--){
        int x = (c-'0')*(num[i]-'0')+carry;
        carry = x/10;
        x=x%10;
        result = char(x+'0')+result;
    }
    if(carry)
        result = char(carry+'0')+result;
    return result;
}

string add(string num1, string num2){
    int carry=0;
    string result;
    if(num1.size()>num2.size()){
        int x = num1.size()-num2.size();
        for(int i=0; i<x; i++)
            num2 = "0"+num2;
    }
    else{
        int x = num2.size()-num1.size();
        for(int i=0; i<x; i++)
            num1 = "0"+num1;
    }
    for(int i=max(num1.size()-1,num2.size()-1);i>=0;i--){
        int x = carry+(num1[i]-'0')+(num2[i]-'0');
        carry = x/10;
        x=x%10;
        result = char(x+'0')+result;
    }
    if(carry)
        result = char(carry+'0')+result;
    return result;
}

string multiply(string num1, string num2){
    string result;
    if(num1.size() == 0 || num2.size() == 0) return "0";
    if(num1.size()==1 && num1[0]=='0' || num2.size()==1 && num2[0]=='0') return "0";
    for(int i=num2.size()-1;i>=0;i--){
        string x;
        x = mul(num1, num2[i]);
        for(int j=0; j<num2.size()-1-i; j++)
            x = x+"0";
        result = add(result, x);
    }
    return result;
}

int main(){
  string res = multiply("7967", "7067");
  printf("%s\n", res.c_str());
  return 0;
}
