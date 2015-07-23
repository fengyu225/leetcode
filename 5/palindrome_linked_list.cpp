/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include "header.h"

//bool search(ListNode*& head, int curr, int len){
//    // recursive
//    if(len%2 == 0 && curr==(len-1)/2){
//        ListNode* n = head->next;
//        bool res = head->val == n->val;
//        head = n;
//        return res;
//    }
//    if(len%2 == 1 && curr == (len-1)/2) return true;
//    ListNode* orig = head;
//    head = head->next;
//    bool res = search(head, curr+1, len);
//    head = head->next;
//    res = res && orig->val == head->val;
//    return res;
//}
//
//bool isPalindrome(ListNode* head) {
//    if(!head) return true;
//    int l = 0;
//    ListNode* curr = head;
//    for(;curr;curr=curr->next,l++);
//    return search(head, 0, l);
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