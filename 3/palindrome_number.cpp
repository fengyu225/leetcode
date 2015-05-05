#include "header.h"

bool isPalindrome(int x) {
    if(x<0) return false;
    if(x<10) return true;
    int m = 10,n=1;
    while(x/m>=10) m*=10;
    while(n<m){
        if(x/m %10 != x/n%10) return false;
        m/=10;n*=10;
    }
    return true;
}

int main(){
    //printf("%d\n", isPalindrome(10000021));
    printf("%d\n", isPalindrome(1001));
//    printf("%d\n", isPalindrome(1));
//    printf("%d\n", isPalindrome(-1));
//    printf("%d\n", isPalindrome(INT_MAX));
    return 0;
}
