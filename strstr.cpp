/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

#include "header.h"

// brute force
//int strStr(string haystack, string needle){
//    int h_sz = haystack.length(), n_sz = needle.length();
//    if(n_sz == 0) 0;
//    int res = -1;
//    int start=0,curr=0,curr_n=0;
//    while(curr<h_sz){
//        if(curr_n == n_sz) return start; 
//        if(needle[curr_n] == haystack[curr]){
//            curr_n++;
//            curr++;
//            continue;
//        }
//        curr=++start;
//        curr_n=0;
//    }
//    return curr_n==n_sz?start:res;
//}

void create_next(string& needle, vector<int>& next){
    int n_sz = needle.length();
    int k = -1, curr = 0;
    next[0] = -1;
    while(curr<n_sz){
        if(k == -1 || needle[k] == needle[curr]){
            k++;
            curr++;
            next[curr] = k;
        }
        else k=next[k];
    }
}

// kmp
int strStr(string haystack, string needle){
    int h_sz = haystack.length();
    int n_sz = needle.length();
    if(n_sz>h_sz) return -1;
    if(n_sz == 0) return 0;
    vector<int> next(n_sz+1, -1);
    create_next(needle, next); 
    int h_curr = 0, n_curr = 0;
    while(h_curr<h_sz){
        if(haystack[h_curr] == needle[n_curr]){
            h_curr++;
            n_curr++;
            if(n_curr == n_sz) return h_curr-n_curr;
        }
        else if(next[n_curr] == -1){
            h_curr++;
            n_curr = 0;
        }
        else n_curr = next[n_curr];
    }
    return -1;
}

int main(){
    string haystack = "BBC ABCDAB ABCDABCDABDE";
    string needle = "ABCDABD";
//    string haystack = "babbbbbabb"; 
//    string needle = "bbab";
    int res = strStr(haystack,needle);
    if(res >= 0)
        cout<<haystack.substr(res, needle.length())<<endl;
    return 0;
}
