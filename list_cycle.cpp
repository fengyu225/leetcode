#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct node {
    int val;
    struct node* next;
};


void print_list(struct node* root){
    while(root){
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}

struct node* cycle(struct node* root){
    if(!root || !root->next)
        return NULL;
    struct node* slow = root;
    struct node* fast = root;
    while(1){
        fast = fast->next;
        if(!fast)
            return NULL;
        fast = fast->next;
        if(fast == slow)
            return slow;
        slow = slow->next;
    }
}

int main(){
    struct node n0 = {.val=0,.next=NULL};
    struct node n1 = {.val=1,.next=NULL};
    struct node n2 = {.val=2,.next=NULL};
    struct node n3 = {.val=3,.next=NULL};
    struct node n4 = {.val=4,.next=NULL};
    struct node n5 = {.val=5,.next=NULL};
    n0.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n5.next=&n2;
    struct node* result = cycle(&n0);
    if(!result)
        printf("no cycle\n");
    else
        printf("%d\n", result->val);
    return 0;
}

