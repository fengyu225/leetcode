#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(int arr[], int n){
    ListNode* result = NULL;
    ListNode* curr = NULL;
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(!result)
            result = curr = x;
        else{
            curr->next = x;
            curr = curr->next;
        }
    }
    return result;
}

ListNode *deleteDuplicates(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode* res = head;
    ListNode* tail = head;
    ListNode* curr = head;
    ListNode* next = curr->next;
    while(next){
        if(tail->val == next->val){
            next = next->next;
            continue;
        }
        tail->next = next;
        tail = next;
        next = next->next;
        tail->next = NULL;
    }
    tail->next = NULL;
    return res;
}

int main(){
//    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int arr[] = {1, 2, 2};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    l = deleteDuplicates(l);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
