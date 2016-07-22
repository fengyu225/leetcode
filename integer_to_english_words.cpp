/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include "header.h"

unordered_map<string,string> m = {
    {0, ""},
    {"1","One"},
    {"2","Two"},
    {"3","Three"},
    {"4","Four"},
    {"5","Five"},
    {"6","Six"},
    {"7","Seven"},
    {"8","Eight"},
    {"9","Nine"}
};

unordered_map<string,string> m1 = {
    {"10","Ten"},
    {"11","Eleven"},
    {"12","Twelve"},
    {"13","Thirteen"},
    {"14","Fourteen"},
    {"15","Fifteen"},
    {"16","Sixteen"},
    {"17","Seventeen"},
    {"18","Eighteen"},
    {"19","Nineteen"}
};

unordered_map<string,string> m2 = {
    {"2","Twenty"},
    {"3","Thirty"},
    {"4","Forty"},
    {"5","Fifty"},
    {"6","Sixty"},
    {"7","Seventy"},
    {"8","Eighty"},
    {"9","Ninety"}
};

//string spell_thousand(string n){
//    int sz = n.length();
//    string res = "";
//    if(n[0] != '0') res+=m[n.substr(0,1)]+" Hundred ";
//    if(n[1] == '1') res+=m1[n.substr(1,2)];
//    else if(n[1] != '0' && n[1] != '1'){
//        res+=m2[n.substr(1,1)]+" ";
//    }
//    if(n[1] != '1' && n[2] != '0') res+=m[n.substr(2,1)]+" ";
//    if(res.length()>0 && res[res.length()-1] == ' ') res = res.substr(0, res.length()-1);
//    return res;
//}
//
//string numberToWords(int num) {
//    if(num == 0) return "Zero";
//    string n = to_string(num);
//    string arr[3] = {"Billion","Million","Thousand"};
//    string res = "";
//    int k = 3-n.length()%3;
//    if(k<3)
//        for(int i=0; i<k; i++) n = "0"+n;
//    int curr = n.length()-3;
//    string x = spell_thousand(n.substr(curr,3));
//    if(x.length() != 0) res = x;
//    k = 2;
//    curr -= 3;
//    while(curr>=0){
//        x = spell_thousand(n.substr(curr,3));
//        if(x.length() != 0) res = x+" "+arr[k]+" "+res;
//        curr -= 3;
//        k--;
//    }
//    if(res.length()>0 && res[res.length()-1] == ' ') res = res.substr(0, res.length()-1);
//    return res;
//}

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
    cout<<"|"<<numberToWords(123)<<"|"<<endl;
    cout<<"|"<<numberToWords(12345)<<"|"<<endl;
    cout<<"|"<<numberToWords(1234567)<<"|"<<endl;
    cout<<"|"<<numberToWords(1000010)<<"|"<<endl;
    cout<<"|"<<numberToWords(1010000)<<"|"<<endl;
    cout<<"|"<<numberToWords(INT_MAX)<<"|"<<endl;
    return 0;
}