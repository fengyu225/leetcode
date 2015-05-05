#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class comp{
    public:
        bool operator () (ListNode* a, ListNode* b){
            if(!a)
                return true;
            if(!b) return false;
            return b->val<a->val;
        }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, comp> q;
    for(int i=0; i<lists.size(); i++) q.push(lists[i]);
    ListNode* res = NULL;
    ListNode* curr = NULL;
    while(!q.empty() && q.top()){
        ListNode* x = q.top();
        q.pop();
        q.push(x->next);
        if(res){
            curr->next = x;
            curr = x;
        }
        else
            res = curr = x;
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
