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
    string flag = numerator<=0&&denominator<0 || numerator>=0&&denominator>0?"":"-";
    long n = abs((long)numerator);
    long d = abs((long)denominator);
    if(n%d == 0) return flag+to_string(n/d);
    if(d == 0) return "inf";
    string res = flag;
    res += to_string(n/d)+".";
    n = n%d;
    unordered_map<int,int> m;
    int index = 0; string temp = "";
    while(n){
        if(m.find(n) != m.end()) break;
        temp += to_string(n*10/d);
        m[n] = index++;
        n = n*10%d;
    }
    if(n == 0) return res+temp;
    temp.insert(m[n], "(");
    temp+=')';
    return res+temp;
}

int main(){
//    cout<<fractionToDecimal(1,2)<<endl;
//    cout<<fractionToDecimal(1,1001)<<endl;
    cout<<fractionToDecimal(-50,8)<<endl;
//    cout<<fractionToDecimal(2,1)<<endl;
//    cout<<fractionToDecimal(2,3)<<endl;
//    cout<<fractionToDecimal(12,14)<<endl;
    return 0;
}