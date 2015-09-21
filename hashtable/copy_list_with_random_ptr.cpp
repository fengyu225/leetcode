/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

#include "header.h"

void addToList(RandomListNode*& res, RandomListNode*& res_curr, RandomListNode* x){
    if(!x) return;
    x->next = NULL;
    if(!res) res = x;
    else res_curr->next = x;
    res_curr = x;
}

RandomListNode *copyRandomList(RandomListNode *head) {
    if(!head) return NULL;
    RandomListNode* curr = head;
    while(curr){
        RandomListNode* n = curr->next;
        RandomListNode* x = new RandomListNode(curr->label);
        curr->next = x;
        x->next = n;
        curr = n;
    }
    curr = head;
    while(curr){
        if(curr->random){
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    RandomListNode* res = NULL, *res_curr = NULL;
    curr = head;
    while(curr){
        RandomListNode* n = curr->next->next;
        RandomListNode* x = curr->next;
        curr->next = n;
        addToList(res,res_curr,x);
        curr = n;
    }
    return res;
}

int main(){
    RandomListNode n0(0);
    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);
    RandomListNode n4(4);
    RandomListNode n5(5);
    n0.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n0.random=&n3;
    n1.random=&n1;
    n2.random=&n4;
    n3.random=&n5;
    n4.random=&n2;
    print_random_list(&n0);
    RandomListNode* r = copyRandomList(&n0);
    print_random_list(r);
    return 0;
}

