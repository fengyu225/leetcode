/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:

"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function.
*/

#include "header.h"



int main(){
    cout<<calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
    cout<<calculate(" 21-1 + 2 ")<<endl;
    cout<<calculate("  2 ")<<endl;
    cout<<calculate("2147483647")<<endl;
    return 0;
}