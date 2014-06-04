#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<queue>

using std::queue;

//bool isMatch(const char* s, const char* p){
//    if(!*p) return *s=='\0';
//    if(!*s) return *p=='\0' || *p=='*';
//    return ((*p=='?' || *p==*s) && isMatch(s+1,p+1)) || (*p=='*' && (isMatch(s,p+1) || isMatch(s+1,p+1) || isMatch(s+1,p)));
//}

bool isMatch(const char *s, const char *p) {
    const char* star=NULL;
    const char* ss=s; 
    while (*s){
        printf("-------------------\n");
        printf("p: %s, s: %s\n", p, s);
        if ((*p=='?')||(*p==*s)){s++;p++;continue;}
        if (*p=='*'){star=p++; ss=s;continue;}
        if (star){ p = star+1; s=++ss;continue;}
        return false;
    }
    while (*p=='*'){p++;}
    return !*p;
}


//bool isMatch(const char* s, const char* p){
//    queue<const char*> s_q;
//    queue<const char*> p_q;
//    s_q.push(s); p_q.push(p);
//    while(!s_q.empty() && !p_q.empty()){
//        const char* s_t = s_q.front();
//        const char* p_t = p_q.front();
//        s_q.pop(); p_q.pop();
//        if(!*p_t){
//            if(*s_t=='\0') return true;
//            else continue;
//        }
//        if(!*s_t){
//            if(*p_t=='\0' || *p_t=='*') return true;
//            else continue;
//        }
//        if(*p_t=='?' || *p_t==*s_t){
//            s_q.push(s_t+1);
//            p_q.push(p_t+1);
//            continue;
//        }
//        if(*p_t=='*'){
//            s_q.push(s_t);p_q.push(p_t+1);
//            s_q.push(s_t+1);p_q.push(p_t+1);
//            s_q.push(s_t+1);p_q.push(p_t);
//            continue;
//        }
//    }
//    return false;
//}

int main(){
//    printf("%s\n", isMatch("aa","a")?"true":"false");
//    printf("%s\n", isMatch("aa","aa")?"true":"false");
//    printf("%s\n", isMatch("aaa","aa")?"true":"false");
//    printf("%s\n", isMatch("aa", "*")?"true":"false");
//    printf("%s\n", isMatch("aa", "a*")?"true":"false");
    printf("%s\n", isMatch("cdadadabe", "?*a*?")?"true":"false");
//    printf("%s\n", isMatch("aab", "c*a*b")?"true":"false");
    return 0;
}
