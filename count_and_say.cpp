/*
 The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 

*/

#include "header.h"

string count(string s){
    string res;
    int begin = 0, curr = 0;
    while(curr<s.size()){
        if(s[curr] == s[begin]){
            curr++;
            continue;
        }
        res += to_string(curr-begin);
        res += s[begin];
        begin = curr;
    }
    res += to_string(curr-begin);
    res += s[begin];
    return res;
}

string countAndSay(int n) {
    string curr = "1";
    for(int i=1; i<n; i++){
        curr = count(curr);
    }
    return curr;
}

int main(){
    string res = countAndSay(5);
    cout<<res<<endl;
    return 0;
}
