/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

#include "header.h"

//int countDigitOne(int);
//
//int countDigitOne(int n, int x){
//    if(n == 0) return 0;
//    if(n<10 || x==1) return 1;
//    if(n/x == 1) return n-n/x*x+1+countDigitOne(n-n/x*x)+countDigitOne(x-1);
//    return x+n/x*countDigitOne(x-1)+countDigitOne(n-n/x*x);
//}
//
//int countDigitOne(int n) {
//    if(n <= 0) return 0;
//    int x = 1, y=n;
//    for(;y>=10;x*=10,y/=10);
//    return countDigitOne(n, x);
//}

/*
Go through the digit positions by using position multiplier m with values 1, 10, 100, 1000, etc.

For each position, split the decimal representation into two parts, for example split n=3141592 into a=31415 and b=92 when we're at m=100 for analyzing the hundreds-digit. And then we know that the hundreds-digit of n is 1 for prefixes "" to "3141", i.e., 3142 times. Each of those times is a streak, though. Because it's the hundreds-digit, each streak is 100 long. So (a / 10 + 1) * 100 times, the hundreds-digit is 1.

Consider the thousands-digit, i.e., when m=1000. Then a=3141 and b=592. The thousands-digit is 1 for prefixes "" to "314", so 315 times. And each time is a streak of 1000 numbers. However, since the thousands-digit is a 1, the very last streak isn't 1000 numbers but only 593 numbers, for the suffixes "000" to "592". So (a / 10 * 1000) + (b + 1) times, the thousands-digit is 1.

The case distincton between the current digit/position being 0, 1 and >=2 can easily be done in one expression. With (a + 8) / 10 you get the number of full streaks, and a % 10 == 1 tells you whether to add a partial streak.
*/
int countDigitOne(int n) {
    int ones = 0;
    for (long long m = 1; m <= n; m *= 10) {
        int a = n/m, b = n%m;
        ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
}

int main(){
    //cout<<countDigitOne(20)<<endl;
    //cout<<countDigitOne(13)<<endl;
    cout<<countDigitOne(1011)<<endl;
    //cout<<countDigitOne(212)<<endl;
    //cout<<countDigitOne(999)<<endl;
    //cout<<countDigitOne(9999)<<endl;
    return 0;
}