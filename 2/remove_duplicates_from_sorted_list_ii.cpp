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
    ListNode* result = NULL, *tail = NULL;
    ListNode* prev = head, *next=prev->next;
    if(!head || !head->next) return head;
    while(next){
        if(prev->val == next->val){
            next = next->next;
            continue;
        }
        if(prev->next == next){
            if(!result)
                result = tail = prev;
            else{
                tail->next = prev;
                tail = tail->next;
            }
        }
        prev = next;
        next = next->next;
    }
    ListNode* x = prev->next?NULL:prev;
    if(tail)
        tail->next = x;
    else
        result = x;
    return result;
}

int main(){
    //int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int arr[] = {1, 2, 3};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    l = deleteDuplicates(l);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
