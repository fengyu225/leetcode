#include "header.h"

bool isPalindrome(int x) {
    if(x<0) return false;
    int m=10,n=1;
    int temp=x;
    while(temp>=10){
        temp/=10;
        n*=10;
    }
    while(m<=n){
        int l=x-x/m*m;
        int r=x/n % 10;
        if(l!=r) return false;
        n/=10;m*=10;
    }
    return true;
}

int main(){
    //printf("%d\n", isPalindrome(10000021));
    printf("%d\n", isPalindrome(1001));
    printf("%d\n", isPalindrome(1));
    printf("%d\n", isPalindrome(-1));
    printf("%d\n", isPalindrome(INT_MAX));
    return 0;
}
