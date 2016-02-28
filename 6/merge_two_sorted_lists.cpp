/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/

#include "header.h"

void addToList(ListNode*& res, ListNode*& res_curr, ListNode* l){
    if(!l) return;
    l->next = NULL;
    if(!res) res = l;
    else res_curr->next = l;
    res_curr = l;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res = NULL, *res_curr = NULL;
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode* l1_curr = l1, *l2_curr = l2;
    while(l1_curr || l2_curr){
        int l1_val = l1_curr?l1_curr->val:INT_MAX;
        int l2_val = l2_curr?l2_curr->val:INT_MAX;
        if(l1_val<l2_val){
            ListNode* temp = l1_curr->next;
            addToList(res, res_curr, l1_curr);
            l1_curr = temp;
        }
        else{
            ListNode* temp = l2_curr->next;
            addToList(res, res_curr, l2_curr);
            l2_curr = temp;
        }
    }
    return res;
}

int main(){
    //int arr1[] = {1, 3, 7};
    vector<int> arr1 = {};
    vector<int> arr2 = {1, 2, 4};
    vector<ListNode*> lists;
    ListNode* head1 = create_list(arr1);
    ListNode* head2 = create_list(arr2);
    ListNode* res = mergeTwoLists(head1, head2);
    print_list(res);
    return 0;
}
