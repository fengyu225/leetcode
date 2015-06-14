/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

#include "header.h"

// merge sort

void addToSorted(ListNode*& new_head, ListNode*& new_tail, ListNode* temp){
    if(!new_head) new_head = temp;
    else new_tail->next = temp;
    new_tail = temp;
    new_tail->next = NULL;
}

ListNode *sortList(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode* slow=head, *fast = head;
    while(fast){
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        if(!fast) break;
        slow = slow->next;
    }
    ListNode* second = slow->next, *first = head;
    slow->next = NULL;
    first = sortList(first);
    second = sortList(second);
    ListNode* new_head=NULL, *new_tail=NULL;
    while(first || second){
        ListNode* f_n = first?first->next:NULL;
        ListNode* s_n = second?second->next:NULL;
        ListNode* temp = first && (!second || first->val<second->val)?first:second;
        addToSorted(new_head, new_tail, temp);
        if(temp==first) first = f_n;
        else second=s_n;
    }
    return new_head;
}

int main(){
    int arr[] = {10, 9, 8, 1, 2, 3};
    ListNode* root = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    ListNode* curr = sortList(root);
    while(curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
