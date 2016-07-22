/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include "header.h"

int getLength(ListNode* x){
    int res = 0;
    while(x){
        res++;
        x = x->next;
    }
    return res;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return NULL;
    int a_len = getLength(headA);
    int b_len = getLength(headB);
    int m = min(a_len, b_len);
    for(int i=0; i<a_len-m; i++) headA = headA->next;
    for(int i = 0; i<b_len-m; i++) headB = headB->next;
    while(headA && headB){
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main(){
    int arr[] = {4, 5, 6};
    ListNode* c = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* seven = new ListNode(7);
    ListNode* eight = new ListNode(8);
    ListNode* nine = new ListNode(9);
    two->next = three;
    three->next = c;
    seven->next = eight;
    eight->next = nine;
    nine->next = c;
    ListNode* res = getIntersectionNode(seven, two);
    if(res)
        cout<<res->val<<endl;
    else
        cout<<"NULL"<<endl;
    return 0;
}