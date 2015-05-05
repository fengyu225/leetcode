#include<stdio.h>
#include<stdlib.h>

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void expend(TreeLinkNode*& head, TreeLinkNode*& tail, TreeLinkNode* c){
    if(!c) return;
    if(!head)
        head = tail = c;
    else{
        tail->next = c;
        tail  = c;
    }
    tail->next = NULL;
}

void connect(TreeLinkNode* root){
    TreeLinkNode* curr = root;
    TreeLinkNode* next_head = NULL;
    TreeLinkNode* next_tail = NULL;
    while(1){
        if(!curr){
            if(!next_head) break;
            curr = next_head;
            next_head = next_tail = NULL;
        }
        else{
            expend(next_head, next_tail, curr->left);
            expend(next_head, next_tail, curr->right);
            curr = curr->next;
        }
    }
}

int main(){
    struct TreeLinkNode n4(4);
    struct TreeLinkNode n5(5);
    struct TreeLinkNode n7(7);
    struct TreeLinkNode n2(2);
    struct TreeLinkNode n3(3);
    struct TreeLinkNode n1(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;
    connect(&n1);
    return 0;
}
    
