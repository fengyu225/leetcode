#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

int divide(int divident, int divisor){
    bool sign = (divident<0 && divisor<0) || (divident>0 && divisor>0);
    unsigned int u_divident = divident<0?-1*divident:divident;
    unsigned int u_divisor = divisor<0?-1*divisor:divisor;
    if(u_divident<u_divisor)
        return 0;
    int ans = 0;
    for(int i=31; i>=0; i--){
        if((u_divident>>i)>=u_divisor){
            ans+=(1<<i);
            u_divident -= (u_divisor<<i);
        }
    }
    return sign?ans:-1*ans;
}

int main(){
    printf("%d\n", divide(-999511578, -2147483648));
    printf("%d\n", divide(100579234, -555806774));
    printf("%d\n", divide(-2147483648, 1));
    printf("%d\n", divide(5, 2));
    printf("%d\n", divide(1, -1));
    return 0;
}
