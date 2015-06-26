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
    for(int i=1; i<next.size(); i++){
        int last = next[i-1];
        if(last>=0 && needle[last]==needle[i]) next[i]=last+1;
        else next[i] = 0;
    }
    for(int i=0; i<next.size(); i++) cout<<next[i]<<" ";
    cout<<endl;
}

// kmp
int strStr(string haystack, string needle){
    int h_sz = haystack.length(), n_sz = needle.length();
    if(n_sz == 0) return 0;
    vector<int> next(n_sz, -1);
    create_next(needle, next);
    int h_start = 0, curr = 0;
    while(h_start<=h_sz-n_sz){
        if(haystack[h_start+curr] == needle[curr]){
            if(curr == n_sz-1) return h_start;
            curr++;
            continue;
        }
        if(curr == 0) h_start++;
        else{
            int m = next[curr-1]==-1?curr-1:next[curr-1];
            h_start+=curr-m;
            curr = 0;
        }
    }
    return -1;
}

int main(){
    //string haystack = "BBC ABCDAB ABCDABCDABDE";
    //string needle = "ABCDABD";
    string haystack = "babbbbbabb"; 
    string needle = "bbab";
    int res = strStr(haystack,needle);
    if(res >= 0)
        cout<<haystack.substr(res, needle.length())<<endl;
    return 0;
}
