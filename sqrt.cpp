#include "header.h"

int sqrt(int x){
    if(x==0 || x==1) return x;
    int l=0,r=x;
    while(l+1<r){
        int m = (l+r)/2;
        if(m==x/m) return m;
        else if(m>x/m) r=m;
        else l=m;
    }
    return l;
}

int main(){
    printf("%d\n", sqrt(5));
    printf("%d\n", sqrt(0));
    printf("%d\n", sqrt(1));
    printf("%d\n", sqrt(16));
    printf("%d\n", sqrt(2147395599));
    return 0;
}
