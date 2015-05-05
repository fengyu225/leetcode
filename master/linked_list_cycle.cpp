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

bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast){
        slow = slow->next;
        fast = fast->next;
        if(!fast) return false;
        fast = fast->next;
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    int arr[] = {0, 1, 2, 3};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]), 0);
    bool r = hasCycle(l);
    printf("%s\n", r?"true":"false");
    return 0;
}
