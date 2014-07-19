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

ListNode* swapPairs(ListNode *head) {
    //1 2 3 4 5 6 7
    //2 1 4 3 6 5 7
    if(!head || !head->next) return head;
    ListNode* curr = head;
    ListNode* res = NULL;
    ListNode* last_tail = NULL;
    while(1){
        if(!curr) return res;
        ListNode* a = curr;
        if(!curr->next){
            if(last_tail) last_tail->next = curr;
            return res;
        }
        ListNode* b = curr->next;
        curr = b->next;
        b->next = a;
        if(!res) res = b;
        else last_tail->next = b;
        last_tail = a;
        last_tail->next = NULL;
    }
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = swapPairs(l);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
