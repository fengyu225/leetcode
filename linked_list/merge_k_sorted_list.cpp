/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include "header.h"

class cmp{
    public:
        bool operator() (ListNode*& a, ListNode*& b){
            if(!a || a && b && a->val>b->val) return true;
            else return false;
        }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int sz = lists.size();
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    ListNode* res = NULL, *curr = NULL;
    for(int i=0; i<sz; i++) pq.push(lists[i]);
    while(!pq.empty() && pq.top() != NULL){
        ListNode* temp = pq.top();
        pq.pop();
        pq.push(temp->next);
        if(!res) res = temp;
        else curr->next = temp;
        curr = temp;
    }
    return res;
}

int main(){
    int arr0[] = {};
    int arr1[] = {1};
    int arr2[] = {2,5,8,10};
    ListNode* head0 = create_list(arr0,sizeof(arr0)/sizeof(arr0[0]));
    ListNode* head1 = create_list(arr1,sizeof(arr1)/sizeof(arr1[1]));
    ListNode* head2 = create_list(arr2,sizeof(arr2)/sizeof(arr2[2]));
    vector<ListNode*> lists = {head0, head1, head2};
    ListNode* res = mergeKLists(lists);
    print_list(res);
    return 0;
}
