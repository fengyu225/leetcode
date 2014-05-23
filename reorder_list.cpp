#include<stdlib.h>
#include<stdio.h>

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

struct node* reverse(struct node* root){
    if(!root)
        return NULL;
    struct node* curr;
    struct node* before = root;
    curr = root->next;
    before->next = NULL;
    while(curr){
        struct node* temp = curr->next;
        curr->next = before;
        before = curr;
        curr = temp;
    }
    return before;
}


void reorder(struct node* root){
    struct node* slow = root;
    struct node* fast = slow;
    while(fast){
        fast = fast->next;
        if(!fast)
            break;
        fast = fast->next;
        slow = slow->next;
    }
    struct node* second_root = reverse(slow->next);
    slow->next = NULL;
    struct node* curr = second_root;
    struct node* before = root;
    while(curr){
        struct node* before_next = before->next;
        struct node* curr_next = curr->next;
        before->next = curr;
        curr->next = before_next;
        before = before_next;
        curr = curr_next;
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
    //struct node* result = reverse(&n0);
    reorder(&n0);
    print_list(&n0);
    return 0;
}

