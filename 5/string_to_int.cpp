#include "header.h"

int myAtoi(string str){
    int res =  0;
    int sz = str.length();
    bool met = false;
    bool neg = false;
    for(int i=0; i<sz; i++){
        if(str[i] == ' ' && !met) continue;
        if((str[i]>'9' || str[i]<'0')){
            if(!met){
                if(str[i] == '-' || str[i] == '+'){
                    neg = str[i] == '-'?true:false;
                    met = true;
                    continue;
                }
                else break;
            }
            else break;
        }
        if(res>INT_MAX/10) return neg?INT_MIN:INT_MAX;
        res *= 10;
        int x = str[i]-'0';
        if(res>INT_MAX-x) return neg?INT_MIN:INT_MAX;
        res += x;
        met = true;
    }
    return neg?-1*res:res;
}

int main(){
//    cout<<myAtoi("     123  45  ")<<endl;
//    cout<<myAtoi(" 10522545459")<<endl;
    cout<<myAtoi("2147483648")<<endl;
//    cout<<myAtoi("2147483647")<<endl;
    return 0;
}
