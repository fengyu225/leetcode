/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include "header.h"

bool isPalindrome(ListNode* head) {

}

int main(){
    int arr[] = {1,0,1};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<isPalindrome(head)<<endl;
    return 0;
}