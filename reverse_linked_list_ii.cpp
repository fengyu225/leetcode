#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head){
    if(!head->next) return head;
    ListNode* curr = head;
    ListNode* next = head->next;
    head->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

void add_node(ListNode*& head, ListNode*& tail, ListNode* c){
    if(!head)
        head = tail = c;
    else{
        tail->next = c;
        tail = c;
    }
}

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m == n || !head || !head->next) return head;
    ListNode* res = NULL;
    ListNode* tail = NULL;
    ListNode* first = NULL;
    ListNode* second = NULL;
    int i = 1;
    ListNode* curr = head;
    while(curr){
        if(i<m){
            add_node(res,tail,curr);
            curr = curr->next;
            i++;
            continue;
        }
        ListNode* first = curr;
        while(i<=n){
            second = curr;
            curr = curr->next;
            i++;
        }
        second->next = NULL;
        reverse(first);
        add_node(res,tail,second);
        first->next = curr;
        curr = NULL;
    }
    return res;
}

ListNode* create_list(int arr[], int n){
    ListNode* result = NULL;
    ListNode* curr = NULL;
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(!result)
            result = curr = x;
        else{
            curr->next = x;
            curr = curr->next;
        }
    }
    return result;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* l = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    l = reverseBetween(l,1,5);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
