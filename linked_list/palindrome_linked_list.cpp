/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include "header.h"

bool check(ListNode*& head, int l, int r){
    if(l>r) return true;
    if(l == r){
        head = head->next;
        return true;
    }
    int l_v = head->val;
    head = head->next;
    bool x = check(head, l+1, r-1);
    bool res = x && l_v == head->val;
    head = head->next;
    return res;
}

bool isPalindrome(ListNode* head) {
    if(!head) return true;
    int len = 0;
    ListNode* x = head;
    for(;x;x=x->next, len++);
    return check(head, 0, len-1);
}

int main(){
    //int arr[] = {1,0,1};
    //int arr[] = {1};
    int arr[] = {};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<isPalindrome(head)<<endl;
    return 0;
}