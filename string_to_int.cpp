#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int atoi(const char *str) {
    const char* curr = str;
    bool found = false, num_met = false;
    int n = 0;
    char sign = ' ';
    for(;*curr;curr++){
        if(*sign == ' ' && (*curr=='+' || *curr=='-')){
            *sign = *curr;
            continue;
        }
        if(*curr<='9' && *curr>='0'){
            n = 10*n+(*curr-'0');
            continue;
        }
        if(*curr == ' ' && !num_met){
            num_met = true;
            continue;
        }

    }
    return sign=='-':-1*n?n;
}

int main(){
    char str0[] = "     123  ";
    char str1[] = "12,345";
    char str2[] = "       ";
    char str3[] = "   123456789999999999999999888888       ";
    printf("%d\n", atoi(str0));
    printf("%d\n", atoi(str1));
    printf("%d\n", atoi(str2));
    printf("%d\n", atoi(str3));
    return 0;
}
