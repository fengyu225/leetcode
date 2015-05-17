#include "header.h"

int reverse(int x){
    //overflow, 0s 
    bool neg = x<0?true:false;
    x=abs(x);
    int res = 0;
    while(x!=0){
        int temp = x<10?x:x-x/10*10;
        if(res>INT_MAX/10) return 0;
        res = res*10+temp;
        x=x/10;
    }
    return neg?-1*res:res;
}

int main(){
    cout<<reverse(100)<<endl;
    cout<<reverse(123)<<endl;
    cout<<reverse(-123)<<endl;
    return 0;
}