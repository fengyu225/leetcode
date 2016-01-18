/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

#include "header.h"

bool isNumber(string s) {
    int l = 0, r = s.length()-1;
    for(;s[l] == ' ';l++);
    for(;s[r] == ' ';r--);
    bool dot=false, e=false, num=false, num_after_dot=false, num_after_e=false;
    if(s[l] == '-' || s[l] == '+') l++;
    if(l > r) return false;
    while(l<=r){
        if(s[l] == '.'){
            if(dot || e) return false;
            dot = true;
        }
        else if(s[l] == ' ') return false;
        else if(s[l] == 'e'){
            if(e || !num) return false;
            e = true;
            if(l+1<=r && (s[l+1] == '-' || s[l+1] == '+')) l++;
        } 
        else if(s[l]>='0' && s[l]<='9'){
            num = true;
            if(dot) num_after_dot=true;
            if(e) num_after_e=true;
        }
        else return false;
        l++;
    }   
    if(!num && (dot || e)) return false;
    if(e && !num_after_e) return false;
    return true;
}

int main(){
    cout<<isNumber("0e")<<endl;
    cout<<isNumber("0")<<endl;
    cout<<isNumber(".")<<endl;
    cout<<isNumber("1  ")<<endl;
    cout<<isNumber("3")<<endl;
    cout<<isNumber("3.")<<endl;
    cout<<isNumber("abc")<<endl;
    cout<<isNumber("1 a")<<endl;
    cout<<isNumber("2e10")<<endl;
    cout<<isNumber("2e1.23")<<endl;
    return 0;
}