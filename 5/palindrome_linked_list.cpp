/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include "header.h"

//bool check(ListNode*& head, int l, int r){
//    if(l>r) return true;
//    if(l == r){
//        head = head->next;
//        return true;
//    }
//    int l_v = head->val;
//    head = head->next;
//    bool x = check(head, l+1, r-1);
//    bool res = x && l_v == head->val;
//    head = head->next;
//    return res;
//}
//
//bool isPalindrome(ListNode* head) {
//    if(!head) return true;
//    int len = 0;
//    ListNode* x = head;
//    for(;x;x=x->next, len++);
//    return check(head, 0, len-1);
//}

ListNode* reverse(ListNode* head){
    if(!head) return NULL;
    ListNode* curr = head, *next = head->next;
    curr->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode* slow = head, *fast = head;
    while(fast){
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        if(!fast) break;
        slow = slow->next;
    }
    ListNode* temp = reverse(slow->next);
    slow->next = NULL;
    while(head && temp){
        if(head->val != temp->val) return false;
        head = head->next;
        temp = temp->next;
    }
    return (!head || !head->next) && !temp;
}

int main(){
    int arr[] = {1,0,1};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<isPalindrome(head)<<endl;
    return 0;
}