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

string countAndSay(int n) {
    if(n == 1) return "1";
    string curr = "1";
    for(int i=1; i<n; i++){
        string temp = "";
        int j = 1;
        char c = curr[0];
        int cnt = 1;
        while(j<curr.length()){
            if(curr[j] == curr[j-1]) cnt++;
            else{
                temp += (cnt+'0');
                temp += c;
                c = curr[j];
                cnt = 1;
            }
            j++;
        }
        temp += (cnt+'0');
        temp += c;
        curr = temp;
    }
    return curr;
}

int main(){
    string res = countAndSay(5);
    cout<<res<<endl;
    cout<<countAndSay(1)<<endl;
    cout<<countAndSay(2)<<endl;
    cout<<countAndSay(3)<<endl;
    cout<<countAndSay(4)<<endl;
    cout<<countAndSay(5)<<endl;
    cout<<countAndSay(6)<<endl;
    return 0;
}
