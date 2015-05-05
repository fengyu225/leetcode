#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<math.h>

int get_log(int n){
    if(n==0) return 1;
    int m = 0;
    for(;n>0;n/=10,m++);
    return m;
}

int atoi(const char *str) {
    const char* curr = str;
    bool num_met = false;
    int n = 0;
    char sign = ' ';
    for(;*curr;curr++){
        if(sign == ' ' && (*curr=='+' || *curr=='-')){
            sign = *curr;
            continue;
        }
        if(*curr<='9' && *curr>='0'){
            num_met = true;
            int temp = 10*n + (*curr-'0');
            if(n>0 && get_log(temp) != get_log(n)+1)
                return (sign == '-')?INT_MIN:INT_MAX;
            n = temp;
            continue;
        }
        if(*curr == ',') continue;
        if(*curr == ' ' && sign==' ' && !num_met) continue;
        break;
    }
    if(n>INT_MAX) n=0;
    return sign=='-'?-1*n:n;
}

int main(){
    char str0[] = "     123  45  ";
    char str1[] = " 10522545459";
    char str2[] = "-2147483648";
//    char str3[] = "   123456789999999999999999888888       ";
    char str3[] = "2147483647";
    printf("%d\n", atoi(str0));
    printf("%d\n", atoi(str1));
    printf("%d\n", atoi(str2));
    printf("%d\n", atoi(str3));
    return 0;
}
