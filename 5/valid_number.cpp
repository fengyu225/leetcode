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

bool isNumber(string s){
    int i=0;
    int sz = s.size();
    while(s[0]==' ') s.erase(0, 1);
    while(s[s.size()-1]==' ') s.erase(s.size()-1,1);
    bool seen_num = false, seen_e=false, seen_dot=false, seen_coma=false, num_after_e=false;
    bool seen_flag = false;
    if(s[0]=='-'||s[0]=='+'){
        s.erase(0,1);
        seen_flag = true; 
    }
    sz = s.size();
    if(sz == 0) return false;
    for(int i=0; i<sz; i++){
        if(s[i]<='9' && s[i]>='0'){
            seen_num = true;
            if(seen_e) num_after_e=true;
            continue;
        }
        if(s[i] == 'e'){
            if(!seen_num || seen_e || seen_coma) return false;
            seen_e = true;
            if(i+1<sz && (s[i+1]=='-' || s[i+1]=='+')) i++;
            continue;
        }
        if(s[i] == '.'){
            if(seen_dot || seen_e) return false;
            seen_dot = true;
            continue;
        }
        if(s[i] == ','){
            if(!seen_num) return false;
            seen_coma=true;
            continue;
        }
        return false;
    }
    return seen_dot&&!seen_num||seen_e&&!num_after_e?false:true;
}

int main(){
//    cout<<isNumber("0")<<endl;
    cout<<isNumber("1  ")<<endl;
//    cout<<isNumber("abc")<<endl;
//    cout<<isNumber("1 a")<<endl;
//    cout<<isNumber("2e10")<<endl;
    return 0;
}