/*
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

#include "header.h"

void expand(TreeLinkNode*& head, TreeLinkNode*& tail, TreeLinkNode* temp){
    if(!temp) return;
    if(head) tail->next = temp;
    else head=temp;
    tail = temp;
    tail->next = NULL;
}

void connect(TreeLinkNode *root){
    if(!root) return;
    TreeLinkNode* curr = root, *next_head = NULL, *next_tail=NULL;
    while(curr){
        expand(next_head, next_tail, curr->left);
        expand(next_head, next_tail, curr->right);
        curr = curr->next;
        if(!curr){
            curr = next_head;
            next_head=next_tail=NULL;
        }
    }
}

int main(){
    string arr[] = {"1","2","3","4","5","6","7"};
    vector<string> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeLinkNode* root = create_link_tree(v);
    connect(root);
    return 0;
}
    
