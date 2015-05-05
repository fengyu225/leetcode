#include<stdio.h>
#include<stdlib.h>


void reverse(char* s, char* e){
    char temp;
    while(s<e){
        temp=*s;
        *s=*e;
        *e=temp;
        s++;
        e--;
    }
}

void reverse_w(char* s){
    reverse(s, s+(strlen(s)-1));
    char* l=s;
    char* r=l;
    while(1){
        if(!*l)
            break;
        while(*r && *r!=' ') r++;
        reverse(l,r-1);
        while(*r && *r==' ') r++;
        l=r;
    }
}


int main(){
    char s[] = "the sky is blue";
    reverse_w(s);
    printf("%s\n",s);
    return 0;
}
