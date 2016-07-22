/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

#include "header.h"

void addNode(ListNode*& head, ListNode*& curr, ListNode* x){
    if(!head) head = x;
    else curr->next = x;
    curr = x;
    curr->next = NULL;
}

ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;
    bool even = false;
    ListNode* odd_head = NULL, *odd_curr = NULL, *even_head = NULL, *even_curr = NULL;
    while(head){
        ListNode* temp = head->next;
        if(even) addNode(even_head, even_curr, head);
        else addNode(odd_head, odd_curr, head);
        head = temp;
        even = !even;
    }
    odd_curr->next = even_head;
    return odd_head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = create_list(nums);
    ListNode* res = oddEvenList(head);
    print_list(res);
    return 0;
}