#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge_two(ListNode* a, ListNode* b){
    ListNode* res = NULL;
    ListNode* curr = NULL;
    while(a && b){
        ListNode* x = NULL;
        if(a->val<b->val){
            x = a;
            a = a->next;
        }
        else{
            x = b;
            b = b->next;
        }
        if(!res)
            res = curr = x;
        else{
            curr->next = x;
            curr = x;
        }
    }
    if(!res)
        return a?a:b;
    else{
        curr->next = a?a:b;
        return res;
    }
}

ListNode* merge_lists(vector<ListNode*>& lists, int l, int r){
    if(l>r) return NULL;
    if(l == r) return lists[l];
    int m = (l+r)/2;
    ListNode* l_res = merge_lists(lists,l,m);
    ListNode* r_res = merge_lists(lists,m+1,r);
    return merge_two(l_res,r_res);
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.size()<1) return NULL;
    if(lists.size() == 1) return lists[0];
    return merge_lists(lists, 0, lists.size()-1);    
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