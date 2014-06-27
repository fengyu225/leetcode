#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class comparison{
    public:
        bool operator() (ListNode* l, ListNode* r){
            if(!l) return true;
            if(!r) return false;
            return l->val>=r->val;
        }
};


ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, comparison> p_q;
    for(int i=0; i<lists.size(); i++)
        p_q.push(lists[i]);
    ListNode* result = NULL;
    ListNode* c = NULL;
    while(!p_q.empty() && p_q.top()){
        ListNode* curr = p_q.top();
        p_q.pop();
        p_q.push(curr->next);
        if(!result){
            result = curr;
            c = curr;
        }
        else{
            c->next = curr;
            c = curr;
        }
    }
    return result;
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
