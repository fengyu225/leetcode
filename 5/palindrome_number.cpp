#include "header.h"

bool isPalindrome(int x) {
    if(x<0) return false;
    int a = 1, b=1, temp=x;
    while(temp>=10){
        a*=10;
        temp/=10;
    }
    while(a!=1){
        int l = x/a % 10;
        int r = x/b % 10; 
        if(l != r ) return false;
        a/=10;
        b*=10;
    }
    return true;
}

int main(){
    //printf("%d\n", isPalindrome(10000021));
    printf("%d\n", isPalindrome(1001));
    printf("%d\n", isPalindrome(10));
//    printf("%d\n", isPalindrome(1));
//    printf("%d\n", isPalindrome(-1));
//    printf("%d\n", isPalindrome(INT_MAX));
    return 0;
}
