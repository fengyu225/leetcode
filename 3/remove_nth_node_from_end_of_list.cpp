#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(!head) return NULL;
    ListNode* curr = head;
    for(int i=0; i<n-1; i++)
        curr = curr->next;
    if(curr->next == NULL)
        return head->next;
    curr = curr->next;
    ListNode* pre = head;
    while(curr->next){
        pre = pre->next;
        curr = curr->next;
    }
    pre->next = pre->next->next;
    return head;
}

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

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* r = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    r = removeNthFromEnd(r,1);
    while(r){
        printf("%d ", r->val);
        r=r->next;
    }
    printf("\n");
    return 0;
}
