#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct node {
    int val;
    struct node* next;
    struct node* rand;
};

void print_list(struct node* root){
    while(root){
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}

struct node* copy(struct node* n){
    struct node* r = (struct node*)malloc(sizeof(struct node));
    r->val = n->val;
    r->next = n->next;
    r->rand = n->rand;
    return r;
}

struct node* copy_list(struct node* root){
    struct node* curr = root;
    while(curr){
        struct node* t = copy(curr);
        curr->rand = t;
        curr = curr->next;
    }
    curr = root;
    struct node* r = root->rand;
    while(curr->next){
        curr->rand->next = curr->next->rand;
        curr->rand = NULL;
        curr = curr->next;
    }
    curr->rand->next = NULL;
    curr->rand = NULL;
    return r;
}

int main(){
    struct node n0 = {.val=0,.next=NULL,.rand=NULL};
    struct node n1 = {.val=1,.next=NULL,.rand=NULL};
    struct node n2 = {.val=2,.next=NULL,.rand=NULL};
    struct node n3 = {.val=3,.next=NULL,.rand=NULL};
    struct node n4 = {.val=4,.next=NULL,.rand=NULL};
    struct node n5 = {.val=5,.next=NULL,.rand=NULL};
    n0.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    print_list(&n0);
    struct node* r = copy_list(&n0);
    print_list(r);
    return 0;
}

