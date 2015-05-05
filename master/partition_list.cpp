#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    if(!head || !head->next) return head;
    ListNode* lt = NULL;
    ListNode* curr = head;
    ListNode* curr_p = NULL;
    ListNode* result = NULL;
    while(curr){
        if(curr->val>=x){
            curr_p = curr;
            curr = curr->next;
            result = !result?curr_p:result;
        }
        else{
            if(!lt){
                lt = curr;
                curr = curr->next;
                if(curr_p) curr_p->next = curr;
                else curr_p = lt;
                if(result){
                    lt->next = result;
                    result = lt;
                }
            }
            else if(lt->next == curr){
                lt = curr;
                curr_p = curr;
                curr = curr->next;
            }
            else{
                ListNode* x_n = lt->next;
                lt->next = curr;
                curr_p->next = curr->next;
                curr->next = x_n;
                lt = curr;
                curr = curr_p->next;
            }
            result = !result||result->val>=x?lt:result;
        }
    }
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
    //int arr[] = {1, 4, 3, 2, 5, 2};
    int arr[] = {2,1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = partition(l,2);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
