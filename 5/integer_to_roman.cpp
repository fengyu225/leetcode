#include "header.h"

/*
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;
*/

string intToRoman(int num){
    int a[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string b[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res="";
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        if(num<a[i]) continue;
        int r = num/a[i];
        for(int j=0;j<r;j++) res += b[i];
        num -= r*a[i];
    }
    return res;
}

int main(){
    cout<<intToRoman(123)<<endl;
    return 0;
}