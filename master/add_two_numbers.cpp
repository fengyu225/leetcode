#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode* result = NULL;
    ListNode* curr = NULL;
    while(l1 || l2){
        int l1_val = l1?l1->val:0;
        int l2_val = l2?l2->val:0;
        int x = l1_val+l2_val+carry;
        ListNode* c_node = new ListNode(x%10);
        if(result){
            curr->next = c_node;
            curr = c_node;
        }
        else{
            result = c_node;
            curr = result;
        }
        carry = x/10;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
    }
    if(carry) curr->next = new ListNode(carry);
    return result;
}

int main(){
    ListNode n0(2);
    ListNode n1(4);
    ListNode n2(3);
    ListNode n3(5);
    ListNode n4(6);
    ListNode n5(4);
    n0.next = &n1;
    n1.next = &n2;
    n3.next = &n4;
    n4.next = &n5;
    ListNode* res = addTwoNumbers(&n0,&n3);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
