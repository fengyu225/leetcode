#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {
    if(!head || !head->next) return head;
    int len = 1;
    ListNode* curr = head;
    while(curr->next){
        len++;
        curr = curr->next;
    }
    if(k%len == 0) return head;
    curr->next = head;
    for(int i=1;i<=len-k%len;i++){
        curr = curr->next;
    }
    ListNode* result = curr->next;
    curr->next = NULL;
    return result;
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
    ListNode* res = rotateRight(&l1,1);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
