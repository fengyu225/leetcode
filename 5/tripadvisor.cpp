#include "stdlib.h"
#include "stdio.h"

class tree{
public:
    int x;
    tree * l;
    tree * r;
};

int max(int a, int b){
    return a>=b?a:b;
}

void search(tree* curr, int& left_h, int& right_h, int& res){
    if(!curr){
        left_h = right_h = 0;
        return;
    }
    left_h = 0; right_h = 0;
    search(curr->l, left_h, right_h, res);
    res = max(res,left_h+1);
    int new_left_h = left_h+1;
    left_h = 0; right_h = 0;
    search(curr->r, left_h, right_h, res);
    res = max(res,right_h+1);
    int new_right_h = right_h+1;
    left_h = new_left_h;
    right_h = new_right_h;
}

int solution(tree * T){
   if(!T) return -1;
   if(!T->l && !T->r) return 0;
   int left_h = 0, right_h = 0, res=0;
   search(T, left_h, right_h, res);
   return res-1;
}

int main(){
    struct tree * T0 = (struct tree*) malloc(sizeof(struct tree));
    struct tree * T1 = (struct tree*) malloc(sizeof(struct tree));
    struct tree * T2 = (struct tree*) malloc(sizeof(struct tree));
    struct tree * T3 = (struct tree*) malloc(sizeof(struct tree));
    struct tree * T4 = (struct tree*) malloc(sizeof(struct tree));
    struct tree * T5 = (struct tree*) malloc(sizeof(struct tree));
    T0->l = T1;
    T0->r = T2;
    T2->l = T3;
    T3->l = T4;
    T3->r = T5;
    printf("%d\n", solution(T0));
    return 0;
}