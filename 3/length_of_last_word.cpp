#include "header.h"

int lengthOfLastWord(const char *s) {
    int res = 0;
    const char* pre = s;
    const char* curr = s;
    while(*curr){
        if(*curr != ' '){
            res = curr-pre+1;
            curr++;
        }
        else{
            while(*curr && *curr ==' ') curr++;
            if(!*curr) break;
            pre = curr;
            res = 1;
            curr++;
        }
    }
    return res;
}

int main(){
    char s[] = "Hello World s ";
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}
