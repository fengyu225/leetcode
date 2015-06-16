/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
*/

#include "header.h"

string fractionToDecimal(int numerator, int denominator){
    if(numerator == 0) return "0";
    bool flag = ((numerator>0 && denominator > 0) || (numerator < 0 && denominator < 0))?true:false;
    long n = abs((long)numerator);
    long d = abs((long)denominator);
    string res = "";
    res += to_string(n/d);
    unordered_map<int,int> map;
    n = n%d;
    if(n == 0) return flag?res:"-"+res;
    string temp = "";
    int i = 0;
    while(n){
        if(map.find(n) != map.end()) break;
        int x = n*10/d;
        temp += (x+'0');
        map[n] = i++;
        n = n*10%d;
    }
    if(n == 0) return flag?res+"."+temp:"-"+res+"."+temp;
    temp.insert(map[n],"(");
    temp += ')';
    return flag?res+"."+temp:"-"+res+"."+temp;
}

int main(){
    cout<<fractionToDecimal(1,2)<<endl;
    cout<<fractionToDecimal(2,1)<<endl;
    cout<<fractionToDecimal(2,3)<<endl;
    cout<<fractionToDecimal(12,14)<<endl;
    return 0;
}