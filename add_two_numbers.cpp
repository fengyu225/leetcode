#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode* l1_curr = l1;
    ListNode* l2_curr = l2;
    ListNode* res = NULL, *curr = NULL;
    while(l1_curr || l2_curr){
        int l1_val = l1_curr?l1_curr->val:0;
        int l2_val = l2_curr?l2_curr->val:0;
        ListNode* temp = new ListNode((l1_val+l2_val+carry)%10);
        carry = (l1_val+l2_val+carry)/10;
        if(!res){
            res = curr = temp;
        }
        else{
            curr->next = temp;
            curr = temp;
        }
        if(l1_curr) l1_curr=l1_curr->next;
        if(l2_curr) l2_curr=l2_curr->next;
    }
    if(carry){
        if(res) res = new ListNode(carry);
        else curr->next = new ListNode(carry);
    }
    return res;
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
