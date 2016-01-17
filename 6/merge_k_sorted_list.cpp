#include "header.h"

class comp{
    public:
        bool operator() (ListNode*& a, ListNode*& b){
            return b && (!a || b->val<a->val);
        }
};

void addToList(ListNode*& head, ListNode*& tail, ListNode* curr){
    if(!curr) return;
    if(!head) head = curr;
    else tail->next = curr;
    tail = curr;
    curr->next = NULL;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int sz = lists.size();
    if(sz == 0) return NULL;
    if(sz == 1) return lists[0];
    priority_queue<ListNode*, vector<ListNode*>, comp> q;
    for(ListNode* l:lists) q.push(l);
    ListNode* res = NULL, *tail = NULL;
    while(!q.empty() && q.top() != NULL){
        ListNode* curr = q.top();
        q.pop();
        ListNode* temp = curr->next;
        addToList(res, tail, curr);
        q.push(temp);
    }
    return res;
}

int main(){
    vector<int> arr0 = {};
    vector<int> arr1 = {1};
    vector<int> arr2 = {2,5,8,10};
    vector<ListNode*> lists;
    ListNode* head0 = create_list(arr0);
    ListNode* head1 = create_list(arr1);
    ListNode* head2 = create_list(arr2);
    lists.push_back(head0);
    lists.push_back(head1);
    lists.push_back(head2);
    ListNode* res = mergeKLists(lists);
    print_list(res);
    return 0;
}
