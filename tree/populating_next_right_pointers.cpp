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

void addToRes(TreeLinkNode* curr, TreeLinkNode*& res_head, TreeLinkNode*& res_tail){
    if(!curr) return;
    curr->next = NULL;
    if(!res_head) res_head = curr;
    else res_tail->next = curr;
    res_tail = curr;
}

void connect(TreeLinkNode *root) {
    if(!root) return;
    TreeLinkNode* curr = root, *n_head = NULL, *n_tail = NULL;
    while(curr){
        addToRes(curr->left, n_head, n_tail); 
        addToRes(curr->right, n_head, n_tail); 
        curr = curr->next;
        if(!curr){
            curr = n_head;
            n_head = n_tail = NULL;
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
    
