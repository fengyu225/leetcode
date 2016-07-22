#include "header.h"

void build_next(string& needle, vector<int>& next){
    int n_sz = needle.length();
    int k = -1, x=0;
    next[0] = -1;
    while(x<n_sz-1){
        if(k == -1 || needle[x] == needle[k]){
            x++;
            k++;
            next[x] = k;
        }
        else k = next[k];
    }
}

int strStr(string haystack, string needle){
    int h_sz = haystack.length(), n_sz = needle.size();
    if(n_sz == 0) return 0;
    vector<int> next(n_sz, -1);
    build_next(needle, next);
    int h_curr = 0, n_curr = 0;
    while(h_curr<h_sz){
        if(haystack[h_curr] == needle[n_curr]){
            h_curr++;
            n_curr++;
            if(n_curr == n_sz) return h_curr-n_sz;
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
    cout<<strStr("BBC ABCDAB ABCDABCDABDE", "ABCDABD")<<endl;
    return 0;
}