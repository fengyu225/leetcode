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
    ListNode* result = NULL;
    ListNode* curr = NULL;
    ListNode* left = NULL;
    ListNode* last = NULL;
    if(!head) return NULL;
    if(!head->next) return head;
    left = head;
    curr = head->next;
    while(curr){
        if(left->val == curr->val){
            curr = curr->next;
            continue;
        }
        if(curr == left->next){
            if(!result)
                result = left;
            else
                last->next = left;
            last = left;
        }
        left = curr;
        curr = curr->next;
    }
    ListNode* temp = !left->next?left:NULL;
    if(last) last->next = temp;
    else result = temp;
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
