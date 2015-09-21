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

string fractionToDecimal(int numerator, int denominator) {
    if(denominator == 0) return "NaN";
//    if(numerator % denominator == 0) return to_string(numerator/denominator);
    bool flag = numerator>=0 && denominator>0 || numerator<=0 && denominator<0;
    long n = (long)numerator, d = (long)denominator;
    n = abs(n);
    d = abs(d);
    string res = "", temp = "";
    res += to_string(n/d);
    n = n%d;
    if(n == 0) return flag?res:"-"+res;
    unordered_map<int,int> m;
    int curr = 0;
    while(n){
        if(m.find(n) != m.end()) break;
        temp += to_string(n*10/d);
        m[n] = curr;
        curr++;
        n = n*10%d;
    }
    if(n == 0) return flag?res+"."+temp:"-"+res+"."+temp;
    temp.insert(m[n], "(");
    temp += ")";
    return flag?res+"."+temp:"-"+res+"."+temp;
}

int main(){
    cout<<fractionToDecimal(1,2)<<endl;
    cout<<fractionToDecimal(2,1)<<endl;
    cout<<fractionToDecimal(2,3)<<endl;
    cout<<fractionToDecimal(12,14)<<endl;
    cout<<fractionToDecimal(INT_MIN,-1)<<endl;
    return 0;
}