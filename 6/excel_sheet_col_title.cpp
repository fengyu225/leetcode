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
    while(n>0){
        res = string(1, 'A'+(n-1)%26)+res;
        n =(n-1)/26;
    }
    return res;
}

int main(){
    cout<<convertToTitle(26)<<endl;
    cout<<convertToTitle(27)<<endl;
    cout<<convertToTitle(1)<<endl;
    cout<<convertToTitle(28)<<endl;
    cout<<convertToTitle(3)<<endl;
    return 0;    
}