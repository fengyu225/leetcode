#include "header.h"

void addToList(ListNode*& head, ListNode*& tail, ListNode* curr){
    if(!head) head = curr;
    else tail->next = curr;
    tail = curr;
    tail->next = NULL;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res_head = NULL, *res_curr = NULL;
    while(l1 || l2){
        if(l1 && (!l2 || l1->val<l2->val)){
            ListNode* temp = l1->next;
            addToList(res_head, res_curr, l1);
            l1 = temp;
        }
        else{
            ListNode* temp = l2->next;
            addToList(res_head, res_curr, l2);
            l2 = temp;
        }
    }
    return res_head;
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
