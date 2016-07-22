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

/* using DFA
bool isNumber(string s) {
    int sz = s.length(), l = 0, r = sz-1;
    for(;l<sz && s[l] == ' ';l++);
    for(;r>=0 && s[r] == ' ';r--);
    if(l>r) return false;
    string zero_to_9 = "0123456789", plus_minus = "+-", dot = ".", e = "e";
    unordered_map<char, int> labels = {
        {'0', 0},
        {'1', 0},
        {'2', 0},
        {'3', 0},
        {'4', 0},
        {'5', 0},
        {'6', 0},
        {'7', 0},
        {'8', 0},
        {'9', 0},
        {'+', 1},
        {'-', 1},
        {'.', 2},
        {'e', 3}
    };
    vector<vector<int> > transitions = {
        {2, 1, 6, -1},
        {2, -1, 6, -1},
        {2, -1, 3, 5},
        {4, -1, -1, 5},
        {4, -1, -1, 5},
        {7, 8, -1, -1},
        {4, -1, -1, -1},
        {7, -1, -1, -1},
        {7, -1, -1, -1}
    };
    int curr = 0;
    for(;l<=r;l++){
        vector<int> temp = transitions[curr];
        if(labels.find(s[l]) == labels.end()) return false;
        int next = temp[labels[s[l]]];
        if(next == -1) return false;
        curr = next;
    }
    return curr == 2 || curr == 4 || curr == 3 || curr == 7;
}
*/
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
    cout<<isNumber("  00,00.0")<<endl;
    cout<<isNumber("12.3e2")<<endl;
    cout<<isNumber("0.e2")<<endl;
    cout<<isNumber(".1")<<endl;
    cout<<isNumber("1.")<<endl;
    cout<<isNumber(".2e10")<<endl;
    cout<<isNumber("-.1")<<endl;
    return 0;
}