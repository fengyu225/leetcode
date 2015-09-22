/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

#include "header.h"

bool isStrobogrammatic(string num) {
    int sz = num.length();
    if(sz == 0) return true;
    if(sz == 1) return num[0] == '0' || num[0] == '1' || num[0] == '8';
    unordered_map<char,char> m = {
        {'0','0'},
        {'1','1'},
        {'6','9'},
        {'9','6'},
        {'8','8'}
    };
    for(int l = 0, r = sz-1; l<=r; l++, r--){
        if(m.find(num[l]) == m.end() || m[num[l]] != num[r]) return false;
    }
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