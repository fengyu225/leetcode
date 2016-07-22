#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if(!l1 || !l2) return l1?l1:l2;
    ListNode* res = NULL,*curr = NULL;
    while(l1 || l2){
        int l1_val = l1?l1->val:INT_MAX;
        int l2_val = l2?l2->val:INT_MAX;
        ListNode* temp = NULL;
        if(l1_val<=l2_val){
            temp = l1;
            l1 = l1->next;
        }
        else{
            temp = l2;
            l2 = l2->next;
        }
        temp->next = NULL;
        if(res){curr->next=temp;curr=temp;}
        else{
            res = curr = temp;
        }
    }
    return res;
}

ListNode* construct_list(int arr[], int n){
    if(n == 0) return NULL;
    ListNode* result = new ListNode(arr[0]);
    ListNode* curr = result;
    for(int i=1; i<n; i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return result;
}

int main(){
    //int arr1[] = {1, 3, 7};
    int arr1[] = {};
    int arr2[] = {0};
    vector<ListNode*> lists;
    ListNode* head1 = construct_list(arr1,sizeof(arr1)/sizeof(arr1[1]));
    ListNode* head2 = construct_list(arr2,sizeof(arr2)/sizeof(arr2[2]));
    ListNode* res = mergeTwoLists(head1, head2);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
