#include<stdlib.h>
#include<stdio.h>

struct node{
    int val;
    struct node* next;
};

struct node* sort(struct node* first, struct node* last){
    if(first == last){
        last->next = NULL;
        return first;
    }
    struct node* slow = first;
    struct node* fast = slow;
    while(slow->next && fast->next){
        fast = fast->next;
        if(!fast->next)
            break;
        fast = fast->next;
        slow = slow->next;
    }
    struct node* f_s;
    struct node* s_s;
    struct node* temp = slow->next;
    slow->next = NULL;
    f_s = sort(first,slow);
    s_s = sort(temp,last);
    struct node* begin = NULL;
    struct node* end = NULL;
    struct node* before = NULL;
    struct node* curr = NULL;
    while(f_s && s_s){
        if(f_s->val>s_s->val){
            curr = f_s;
            f_s = f_s->next;
        }
        else{
            curr = s_s;
            s_s = s_s->next;
        }
        begin = begin==NULL?curr:begin;
        if(!before)
            before = curr;
        else{
            before->next = curr;
            before = before->next;
        }
    }
    curr->next = f_s==NULL?s_s:f_s;
    while(1){
        if(!curr)
            break;
        end = curr;
        curr = curr->next;
    }
    end->next = NULL;
    return begin;
}

int main(){
    struct node n0 = {.val=3,.next=NULL};
    struct node n1 = {.val=2,.next=NULL};
    struct node n2 = {.val=4,.next=NULL};
    struct node n3 = {.val=1,.next=NULL};
    struct node n4 = {.val=0,.next=NULL};
    struct node n5 = {.val=5,.next=NULL};
    n0.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    struct node* s;
    struct node* t;
    s = sort(&n0, &n5);
    struct node* curr = s;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
