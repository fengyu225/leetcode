#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* next = curr->next;
    curr->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

void reorderList(ListNode *head) {
    if(!head || !head->next) return;
    ListNode* slow = head, *fast = head->next;
    do{
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        slow = slow->next;
    }while(slow && fast);
    ListNode* second = slow->next;
    slow->next = NULL;
    ListNode* temp = reverse(second);
    while(temp){
        ListNode* next = head->next;
        ListNode* second_next = temp->next;
        head->next = temp;
        temp->next = next;
        head = next;
        temp = second_next;
    }
}

int main(){
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    reorderList(&l1);
    ListNode* curr = &l1;
    while(curr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
    return 0;
}
