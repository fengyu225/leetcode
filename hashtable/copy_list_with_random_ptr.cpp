/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

#include "header.h"

RandomListNode *copyRandomList(RandomListNode *head) {
    if(!head) return NULL;

}

int main(){
    RandomListNode n0(0);
    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);
    RandomListNode n4(4);
    RandomListNode n5(5);
    n0.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n0.random=&n3;
    n1.random=&n1;
    n2.random=&n4;
    n3.random=&n5;
    n4.random=&n2;
    print_random_list(&n0);
    RandomListNode* r = copyRandomList(&n0);
    print_random_list(r);
    return 0;
}

