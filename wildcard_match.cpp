#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

bool isMatch(const char* s, const char* p){
    if(!*p) return *s=='\0';
    if(!*s) return *p=='\0' || *p=='*';
    return ((*p=='?' || *p==*s) && isMatch(s+1,p+1)) || (*p=='*' && (isMatch(s,p+1) || isMatch(s+1,p+1) || isMatch(s+1,p)));
}

int main(){
    printf("%s\n", isMatch("aa","a")?"true":"false");
    printf("%s\n", isMatch("aa","aa")?"true":"false");
    printf("%s\n", isMatch("aaa","aa")?"true":"false");
    printf("%s\n", isMatch("aa", "*")?"true":"false");
    printf("%s\n", isMatch("aa", "a*")?"true":"false");
    printf("%s\n", isMatch("ab", "?*")?"true":"false");
    printf("%s\n", isMatch("aab", "c*a*b")?"true":"false");
    return 0;
}
