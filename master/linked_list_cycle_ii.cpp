#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(int arr[], int n, int s){
    ListNode* result = NULL;
    ListNode* curr = NULL;
    ListNode* end = NULL;
    ListNode* start = NULL;
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(arr[i] == s) start=x;
        if(!result)
            result = curr = x;
        else{
            curr->next = x;
            curr = curr->next;
        }
        if(i==n-1) end=curr;
    }
    end->next = start;
    return result;
}

ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next) return NULL;
    if(head->next == head) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(slow && fast){
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
        else return NULL;
        if(slow == fast) break;
    }
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}


int main(){
    int arr[] = {0, 1, 2, 3};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]), 0);
    ListNode* r = detectCycle(l);
    if(r)
        printf("%d\n", r->val);
    return 0;
}
