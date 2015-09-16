/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add operators +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

#include "header.h"

vector<string> addOperators(string num, int target) {

}

int main(){
    vector<string> res = addOperators("123", 6);
    print_vector<string>(res);
    return 0;
}