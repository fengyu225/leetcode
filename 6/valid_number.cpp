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
    return 0;
}