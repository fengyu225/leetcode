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

ListNode *deleteDuplicates(ListNode *head){
    if(!head) return NULL;
    ListNode* res = NULL;
    ListNode* tail = NULL;
    ListNode* curr = head;
    ListNode* next = curr->next;
    while(next){
        if(curr->val == next->val){
            next = next->next;
            continue;
        }
        if(curr->next == next){
            if(res){
                tail->next = curr;
                tail = curr;
            }
            else
                res = tail = curr;
            tail->next = NULL;
        }
        curr = next;
        next = next->next;
    }
    if(!curr->next){
        if(res)
            tail->next = curr;
        else
            res = curr;
    }
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
