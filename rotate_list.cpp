#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {
    if(k == 0 || !head) return head;
    ListNode* l = head;
    ListNode* r = head;
    for(int i=0; i<k+1; i++){
        r = r->next;
        if(!r) r = head;
    }
    while(r){
        l = l->next;
        r = r->next;
        if(!l) l = head;
    }
    ListNode* res = l->next;
    if(!res) return head;
    l->next = NULL;
    ListNode* curr = res;
    while(curr->next) curr = curr->next;
    curr->next = head;
    return res;
}

int main(){
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    ListNode* curr = &l1;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    ListNode* res = rotateRight(&l1,5);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
