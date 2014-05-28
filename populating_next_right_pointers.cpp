#include<stdio.h>
#include<stdlib.h>

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* root){
    TreeLinkNode* prev = root;
    TreeLinkNode* curr_head = NULL;
    TreeLinkNode* curr = NULL;
    while(1){
        if(prev){
            if(prev->left == NULL && prev->right == NULL){
                prev = prev->next;
                continue;
            }
            if(!curr){
                curr = prev->left?prev->left:prev->right;
                curr_head = curr;
            }
            else
                curr->next = prev->left?prev->left:prev->right;
            prev = prev->next;
            printf("curr_head: %d, curr: %d\n", curr_head->val, curr->val);
        }
        else{
            if(!curr_head)
                break;
            prev = curr_head;
            curr = NULL;
            curr_head = NULL;
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
    
