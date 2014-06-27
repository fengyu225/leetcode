#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge_lists(vector<ListNode*>& lists, int l, int r){
    if(l>r) return NULL;
    if(l==r) return lists[l];
    int m = (l+r)/2;
    ListNode* l_head = merge_lists(lists,l,m);
    ListNode* r_head = merge_lists(lists,m+1,r);
    ListNode* result = NULL;
    ListNode* curr = NULL;
    while(l_head && r_head){
        ListNode* temp;
        if(l_head->val<r_head->val){
            temp = l_head;
            l_head = l_head->next;
        }
        else{
            temp = r_head;
            r_head = r_head->next;
        }
        if(!result) result = temp;
        if(curr){
            curr->next = temp;
            curr = curr->next;
        }
        else
            curr = temp;
    }
    ListNode* rest = l_head==NULL?r_head:l_head;
    if(rest){
        if(curr)
            curr->next = rest;
        else
            result = rest;
    }
    return result;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    return merge_lists(lists,0,lists.size()-1); 
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
    int arr0[] = {};
    int arr1[] = {1};
//    int arr2[] = {2,5,8,10};
    vector<ListNode*> lists;
    ListNode* head0 = construct_list(arr0,sizeof(arr0)/sizeof(arr0[0]));
    ListNode* head1 = construct_list(arr1,sizeof(arr1)/sizeof(arr1[1]));
//    ListNode* head2 = construct_list(arr2,sizeof(arr2)/sizeof(arr2[2]));
    lists.push_back(head0);
    lists.push_back(head1);
//    lists.push_back(head2);
    ListNode* res = mergeKLists(lists);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
