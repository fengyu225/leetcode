#include "stdlib.h"

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
}; 

ListNode* create_list(int arr[], int n);
