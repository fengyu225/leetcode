/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

#include "header.h"

int strStr(string haystack, string needle){
    int h_sz = haystack.length(), n_sz = needle.length();
    if(n_sz == 0) 0;
    int res = -1;
    int start=0,curr=0,curr_n=0;
    while(curr<h_sz){
        if(curr_n == n_sz) return start; 
        if(needle[curr_n] == haystack[curr]){
            curr_n++;
            curr++;
            continue;
        }
        curr=++start;
        curr_n=0;
    }
    return curr_n==n_sz?start:res;
}

int main(){
    cout<<strStr("hello, world", "o,world")<<endl;
    return 0;
}
