#include "header.h"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void print_list(RandomListNode* root){
    while(root){
        printf("%d ", root->label);
        root = root->next;
    }
    printf("\n");
}

void add_node(RandomListNode*& head, RandomListNode*& tail, RandomListNode* new_node){
    if(!head)
        head = tail = new_node;
    else{
        tail->next = new_node;
        tail = new_node;
    }
    tail->next = NULL;
}

RandomListNode *copyRandomList(RandomListNode *head) {
    if(!head) return NULL;
    RandomListNode* curr = head;
    while(curr){
        RandomListNode* next = curr->next;
        RandomListNode* c = new RandomListNode(curr->label);
        curr->next = c;
        c->next = next;
        curr = next;
    }
    curr = head;
    while(curr){
        if(curr->random)
            curr->next->random = curr->random->next;
        else
            curr->next->random = NULL;
        curr = curr->next->next;
    }
    RandomListNode* res = NULL;
    RandomListNode* tail = NULL;
    curr = head;
    while(curr){
        RandomListNode* temp = curr->next->next;
        add_node(res,tail,curr->next);
        curr->next = temp;
        curr = temp;
    }
    return res;
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
    print_list(&n0);
    RandomListNode* r = copyRandomList(&n0);
    print_list(r);
    return 0;
}

