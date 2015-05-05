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

ListNode* reverse(ListNode* begin, ListNode* end){
    if(begin == end) return begin;
    ListNode* curr = begin->next;
    ListNode* pre = begin;
    while(curr!=end){
        ListNode* t = curr->next;
        curr->next = pre;
        pre = curr;
        curr = t;
    }
    begin->next = NULL;
    if(curr){
        curr->next = pre;
        return curr;
    }
    else
        return pre;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if(k==1) return head;
    if(!head) return head;
    ListNode* result = NULL;
    ListNode* last_end = NULL;
    ListNode* curr = head;
    while(1){
        ListNode* begin = curr;
        ListNode* end = NULL;
        int i;
        for(i=0;i<k-1 && curr;i++){
            curr = curr->next;
        }
        if(!curr){
            if(last_end)
                last_end->next = begin;
            return result?result:head;
        }
        ListNode* temp = curr->next?curr->next:NULL;
        end = curr;
        ListNode* x = reverse(begin,end);
        if(!result) result = x;
        if(last_end) last_end->next = end;
        last_end = begin;
        if(!temp) return result;
        curr = temp;
    }
}

int main(){
    //int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = reverseKGroup(l,2);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
