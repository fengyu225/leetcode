/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

#include "header.h"

string convertToTitle(int n){
    string res = "";
    while(n){
        res += (n-1)%26+'A';
        n = (n-1)/26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout<<convertToTitle(27)<<endl;
    cout<<convertToTitle(1)<<endl;
    cout<<convertToTitle(28)<<endl;
    cout<<convertToTitle(3)<<endl;
    return 0;    
}