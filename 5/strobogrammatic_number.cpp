/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

#include "header.h"

bool isStrobogrammatic(string num) {
    int sz = num.length();
    if(sz == 0) return true;
    if(sz == 1) return num[0] == '0' || num[0] == '8' || num[0] == '1';
    int l = 0, r = sz-1;
    while(l<r){
        if(
                ((num[l] == '6' && num[r] == '9') || (num[l] == '9' && num[r]=='6')) ||
                ((num[l] == '0') && (num[r] == '0')) ||
                (num[l]=='1' && num[r] == '1') ||
                (num[l]=='8' && num[r] == '8')
                ){
            l++;
            r--;
        }
        else return false;
    }
    if(l == r && !(num[l] == '0' || num[l] == '8' || num[l] == '1')) return false;
    return true;
}

int main(){
    cout<<isStrobogrammatic("60809")<<endl;
    //cout<<isStrobogrammatic("101")<<endl;
    //cout<<isStrobogrammatic("33")<<endl;
    //cout<<isStrobogrammatic("69")<<endl;
    //cout<<isStrobogrammatic("818")<<endl;
    return 0;
}