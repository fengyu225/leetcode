#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stack>

using namespace std;

bool is_op(char* s){
    return strcmp(s,"+")==0 || strcmp(s,"-")==0 || strcmp(s,"*")==0 || strcmp(s,"/")==0;
}

int eval_op(int l, int r, char* s){
    if(strcmp(s,"+")==0)
        return l+r;
    if(strcmp(s,"-")==0)
        return l-r;
    if(strcmp(s,"*")==0)
        return l*r;
    if(strcmp(s,"/")==0)
        return l/r;
}

int eval(char* s[], int size){
    stack<char*> stack;
    for(int i=0; i<size; i++){
        if(is_op(s[i])){
                if(stack.size()<2){
                    printf("Incorrect exp\n");
                    return -1;
                }
                int left = atoi(stack.top());
                stack.pop();
                int right = atoi(stack.top());
                stack.pop();
                char v[10];
                int eval_i = eval_op(left,right,s[i]);
                itoa(eval_i, v, 10);
                stack.push(v);
        }
        else
            stack.push(s[i]);
    }
    return atoi(stack.top());
}

int main(){
    char* s[] = {"4", "13", "5", "/", "+"};
    int result = eval(s,sizeof(s)/sizeof(s[0]));
    printf("%d\n", result);
    return 0;
}
