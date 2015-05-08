#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
	if(!l1 || !l2) return l1?l1:l2;
	int val = 0, x=0;
	ListNode* res = NULL;
	ListNode* curr = NULL;
	while(l1 || l2){
		int l1_val = l1?l1->val:0;
		int l2_val = l2?l2->val:0;
		int temp = l1_val+l2_val+x;
		val = temp%10;
		x = temp>9?1:0;
		ListNode* t = new ListNode(val);
		if(curr){
			curr->next = t;
			curr=t;
		}
		else
			res = curr = t;
		if(l1)
			l1 = l1->next;
		if(l2)
			l2 = l2->next;
	}
	if(x){
		if(curr)
			curr->next = new ListNode(x);
		else{
			res = new ListNode(x);
		}
	}
	return res;
}

int main(){
    ListNode n0(2);
    ListNode n1(4);
    ListNode n2(3);
    ListNode n3(5);
    ListNode n4(6);
    ListNode n5(4);
    n0.next = &n1;
    n1.next = &n2;
    n3.next = &n4;
    n4.next = &n5;
    ListNode* res = addTwoNumbers(&n0,&n3);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
