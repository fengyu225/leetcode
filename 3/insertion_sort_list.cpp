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

void insert(ListNode*& head, ListNode* c){
    if(c->val<head->val){
        c->next = head;
        head = c;
        return;
    }
    ListNode* curr = head;
    while(curr->next){
        if(c->val>=curr->val && c->val<curr->next->val){
            c->next = curr->next;
            curr->next = c;
            return;
        }
        curr = curr->next;
    }
    curr->next = c;
    c->next = NULL;
}

ListNode *insertionSortList(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode* res = head;
    ListNode* curr = head->next;
    res->next = NULL;
    while(curr){
        ListNode* x = curr->next;
        insert(head,curr);
        curr = x;
    }
    return head;
}

int main(){
//    int arr[] = {9, 8, 7, 1, 2, 3};
    int arr[] = {0, 0, 0};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = insertionSortList(l);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
