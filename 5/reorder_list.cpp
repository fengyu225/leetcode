/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

#include "header.h"

void expand(ListNode*& res, ListNode*& tail, ListNode* l){
    if(!l) return;
    if(res) tail->next = l;
    else res = l;
    tail = l;
    tail->next = NULL;
}

ListNode* reverse(ListNode* head){
    if(!head) return NULL;
    ListNode* curr = head, *next=curr->next;
    curr->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

void reorderList(ListNode* head){
    if(!head || !head->next) return;
    ListNode* slow = head, *fast = head;
    while(fast){
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        if(!fast) break;
        slow = slow->next;
    }
    ListNode* temp = slow->next;
    slow->next = NULL;
    slow = reverse(temp);
    ListNode* res = NULL, *tail = NULL;
    while(head || slow){
        if(head){
            ListNode* n_head = head->next;
            expand(res,tail,head);
            head = n_head;
        }
        if(slow){
            ListNode* n_slow = slow->next;
            expand(res,tail,slow);
            slow = n_slow;
        }
    }
}

int main(){
    int arr[] = {1, 2, 3, 4};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    reorderList(head);
    ListNode* curr = head;
    while(curr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
    return 0;
}
