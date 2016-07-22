/*
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:

Input:
1->2->3

Output:
1->2->4
*/

#include "header.h"

int plusOneHelper(ListNode* head){
    if(!head->next){
        int temp = (head->val+1)%10;
        int res = (head->val+1)/10;
        head->val = temp;
        return res;
    }
    int carry = plusOneHelper(head->next);
    int temp = (head->val+carry)%10;
    int new_carry = (head->val+carry)/10;
    head->val = temp;
    return new_carry;
}

ListNode* plusOne(ListNode* head) {
    if(!head) return new ListNode(1);
    int carry = plusOneHelper(head);
    if(carry){
        ListNode* new_head = new ListNode(carry);
        new_head->next = head;
        return new_head;
    }
    else return head;
}

/*
ListNode* plusOne(ListNode* head) {
    if (!head)
        return new ListNode(1);
    auto plused = plusOne(head->next);
    head->val += plused != head->next;
    if (head->val <= 9)
        return head;
    head->val = 0;
    plused->next = head;
    return plused;
}
*/

int main(){
    ListNode* head = create_list(vector<int>({9, 9, 9}));
    head = plusOne(head);
    print_list(head);
    return 0;
}
