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

ListNode *insertionSortList(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode* result = NULL;
    ListNode* curr = head->next;
    ListNode* curr_pre = head;
    while(curr){
        ListNode* c = head;
        if(curr->val<=c->val){
            curr_pre->next = curr->next;
            curr->next = c;
            head = curr;
            curr = curr_pre->next;
        }
        else{
            while(c->next != curr && c->next->val<curr->val)
                c = c->next;
            if(c->next != curr){
                curr_pre->next = curr->next;
                curr->next = c->next;
                c->next = curr;
                curr = curr_pre->next;
            }
            else{
                curr_pre = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}

int main(){
    //int arr[] = {9, 8, 7, 1, 2, 3};
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
