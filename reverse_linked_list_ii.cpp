#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
//    if(!head || !head->next) return head;
    ListNode* curr = head;
    ListNode* start = head;
    ListNode* end = head;
    ListNode* pre = NULL;
    ListNode* post = NULL;
    for(int i=0;i<m-1;i++){
        pre = curr;
        curr = curr->next;
    }
    start = curr;
    curr = head;
    post = curr->next;
    for(int i=0; i<n-1;i++){
        curr = post;
        post = post->next;
    }
    end = curr;
    curr = start;
    ListNode* curr_n = curr->next;
    while(curr_n!=post){
        ListNode* x = curr_n->next;
        curr_n->next = curr;
        curr = curr_n;
        curr_n = x;
    }
    start->next = NULL;
    ListNode* result = NULL;
    if(pre){
        pre->next = end;
        result = head;
    }
    else
        result = end;
    start->next = post;
    return result;
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
    ListNode* l = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    l = reverseBetween(l,1,5);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
