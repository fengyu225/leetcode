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
    ListNode* curr = head, *next = head->next;
    bool x = check(next, l+1, r-1);
    bool res = x && curr->val == next->val;
    head = next->next;
    return res;
}

bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode* curr = head;
    int len=0;
    for(ListNode* temp = head; temp; len++,temp = temp->next);
    return check(curr, 0, len-1);
}

int main(){
    int arr[] = {1,0,1};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<isPalindrome(head)<<endl;
    return 0;
}