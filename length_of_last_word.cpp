#include "header.h"

int lengthOfLastWord(const char *s) {
    if(strlen(s)==0) return 0;
    const char* curr = s;
    const char* pre = s;
    int res = 0;
    while(*curr){
        if(*curr!=' '){
            res = curr-pre+1;
            curr++;
        }
        else{
            while(*curr && *curr == ' ')
                curr++;
            if(!*curr) break;
            pre = curr;
            res = curr-pre+1;
        }
    }
    return res;
}

int main(){
    char s[] = "Hello World s ";
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}
