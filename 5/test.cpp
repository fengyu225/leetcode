#include "header.h"

int count(int s, int n){
    //count number of appearence of n in s!
    if(s<n) return 0;
    int curr = s;
    int res = 0;
    while(curr>=n){
        res += curr/n;
        curr = curr/n;
    }
    return res;
}

int main(){
    cout<<count(26,5)<<endl;
    return 0;
}