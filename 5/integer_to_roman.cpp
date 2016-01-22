#include "header.h"

vector<string> key = {
    "M",
    "CM",
    "D",
    "CD",
    "C",
    "XC",
    "L",
    "XL",
    "X",
    "IX",
    "V",
    "IV",
    "I",
};

vector<int> val = {
    1000,
    900,
    500,
    400,
    100,
    90,
    50,
    40,
    10,
    9,
    5,
    4,
    1
};

string intToRoman(int num){
    string res = "";
    if(num == 0) return res;
    int sz = key.size();
    for(int i=0; i<sz; i++){
        if(val[i]>num) continue;
        int r = num/val[i];
        string temp = "";
        for(int j=0; j<r; j++) temp+=key[i];
        res += temp;
        num -= r*val[i];
    }
    return res;
}

int main(){
    cout<<intToRoman(123)<<endl;
    return 0;
}