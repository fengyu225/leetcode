#include "header.h"

char *strStr(char *haystack, char *needle) {
    if(!needle) return NULL;
    if(!*needle) return haystack;
    char* h_head = haystack;
    char* h_curr = h_head;
    char* n_curr=needle;
    while(*h_curr){
        if(!*n_curr) return h_head;
        if(*n_curr != *h_curr){
            h_head++;
            h_curr = h_head;
            n_curr = needle;
        }
        else{
            n_curr++;
            h_curr++;
        }
    }
    return *n_curr?NULL:h_head;
}

int main(){
    printf("%s\n", strStr("hello, world", "o, world"));
    char* res = strStr("hello, world", "o, word");
    printf("%s\n", res?"NULL":"NOT NULL");
//    printf("%s\n", strStr("hello, world", ""));
    return 0;
}
