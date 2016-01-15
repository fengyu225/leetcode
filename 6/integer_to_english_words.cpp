/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include "header.h"

unordered_map<int,string> m = {
    {0, ""},
    {1,"One"},
    {2,"Two"},
    {3,"Three"},
    {4,"Four"},
    {5,"Five"},
    {6,"Six"},
    {7,"Seven"},
    {8,"Eight"},
    {9,"Nine"}
};

unordered_map<int,string> m1 = {
    {10,"Ten"},
    {11,"Eleven"},
    {12,"Twelve"},
    {13,"Thirteen"},
    {14,"Fourteen"},
    {15,"Fifteen"},
    {16,"Sixteen"},
    {17,"Seventeen"},
    {18,"Eighteen"},
    {19,"Nineteen"}
};

unordered_map<int,string> m2 = {
    {0,""},
    {1,"Ten"},
    {2,"Twenty"},
    {3,"Thirty"},
    {4,"Forty"},
    {5,"Fifty"},
    {6,"Sixty"},
    {7,"Seventy"},
    {8,"Eighty"},
    {9,"Ninety"}
};

void trim(string& str){
    int l = 0, r = str.length()-1;
    for(;str[l] == ' ';l++);
    for(;str[r] == ' ';r--);
    if(l>r) str="";
    else str = str.substr(l, r-l+1);
}

string helper(int num){
    string res = "";
    if(num<10) res = m[num];
    else if(num<20) res = m1[num];
    else if(num<100) res = m2[num/10]+" "+helper(num%10);
    else if(num<1000) res = helper(num/100) + " Hundred "+helper(num%100);
    else if(num<1000000) res = helper(num/1000)+ " Thousand "+helper(num%1000);
    else if(num<1000000000) res = helper(num/1000000)+ " Million "+helper(num%1000000);
    else res = helper(num/1000000000)+ " Billion "+helper(num%1000000000);
    trim(res);
    return res;
}

string numberToWords(int num) {
    if(num == 0) return "Zero";
    return helper(num);
}

int main(){
    cout<<"|"<<numberToWords(20)<<"|"<<endl;
    cout<<"|"<<numberToWords(123)<<"|"<<endl;
    cout<<"|"<<numberToWords(12345)<<"|"<<endl;
    cout<<"|"<<numberToWords(1234567)<<"|"<<endl;
    cout<<"|"<<numberToWords(1000010)<<"|"<<endl;
    cout<<"|"<<numberToWords(1010000)<<"|"<<endl;
    cout<<"|"<<numberToWords(INT_MAX)<<"|"<<endl;
    return 0;
}