/*

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/

#include "header.h"

int divide(int dividend, int divisor) {
    if(dividend == 0) return 0;
    bool flag = dividend>=0 && divisor>=0 || dividend<=0 && divisor<=0;
    if(divisor == 0) return flag?INT_MAX:INT_MIN;
    unsigned int dd = dividend>=0?dividend:-1*dividend;
    unsigned int ds = divisor>=0?divisor:-1*divisor;
    if(dd<ds) return 0;
    unsigned int res = 0;
    for(int i=31; i>=0; i--){
        if((dd>>i) >= ds){
            res += (unsigned int)(1<<i);
            dd -= (ds<<i);
        }
    }
    if(res > INT_MAX) return flag?INT_MAX:INT_MIN;
    else return flag?res:-1*res;
}

int main(){
//    printf("%d\n", divide(-999511578, -2147483648));
//    printf("%d\n", divide(100579234, -555806774));
    cout<<sizeof(long)<<" "<<sizeof(int)<<endl;
    printf("%d\n", divide(-2147483648, -1));
    printf("%d\n", divide(-2147483648, 1));
//    printf("%d\n", divide(5, 2));
//    printf("%d\n", divide(1, -1));
    return 0;
}
