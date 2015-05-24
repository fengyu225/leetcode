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

ListNode* reverse(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* curr = head;
    ListNode* next = head->next;
    curr->next = NULL;
    while(next){
        ListNode* x = next->next;
        next->next = curr;
        curr = next;
        next = x;
    }
    return curr;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if(k == 1 || !head || !head->next) return head;
    ListNode* res = NULL;
    ListNode* curr = NULL;
    ListNode* first = head;
    ListNode* second = head;
    while(second){
        for(int i=0; i<k-1; i++){
            second = second->next;
            if(!second) break;
        }
        if(!second) break;
        ListNode* x = second->next;
        second->next = NULL;
        reverse(first);
        if(!res){
            res = second;
            curr = first;
        }
        else{
            curr->next = second;
            curr = first;
        }
        first = second = x;
    }
    if(!res)
        res = first;
    else
        curr->next = first;
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    //int arr[] = {1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = reverseKGroup(l,2);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
