/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include "header.h"

ListNode* mergeKLists(vector<ListNode*>& lists) {

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
