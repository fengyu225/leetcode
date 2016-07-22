#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(vector<ListNode*>& lists, int l, int r){
    if(l>r) return NULL;
    if(l == r) return lists[l];
    int m = (l+r)/2;
    ListNode* l_head = merge(lists, l, m);
    ListNode* r_head = merge(lists, m+1, r);
    ListNode* res = NULL, *curr = NULL;
    while(l_head || r_head){
        int l_val = l_head?l_head->val:INT_MAX;
        int r_val = r_head?r_head->val:INT_MAX;
        ListNode* temp = NULL;
        if(l_val<=r_val){
            temp = l_head;
            l_head = l_head->next;
        }
        else{
            temp = r_head;
            r_head = r_head->next;
        }
        temp->next = NULL;
        if(res){
            curr->next = temp;
            curr = temp;
        }
        else res = curr = temp;
    }
    return res;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int sz = lists.size();
    ListNode* res = merge(lists, 0, sz-1);
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
    int arr0[] = {};
    int arr1[] = {1};
    int arr2[] = {2,5,8,10};
    vector<ListNode*> lists;
    ListNode* head0 = construct_list(arr0,sizeof(arr0)/sizeof(arr0[0]));
    ListNode* head1 = construct_list(arr1,sizeof(arr1)/sizeof(arr1[1]));
    ListNode* head2 = construct_list(arr2,sizeof(arr2)/sizeof(arr2[2]));
    lists.push_back(head0);
    lists.push_back(head1);
    lists.push_back(head2);
    ListNode* res = mergeKLists(lists);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
