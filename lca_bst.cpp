/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

#include "header.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    //recursive
    if(!p || !q) return p?p:q;
    if(!root) return NULL;
    if(root->val==p->val || root->val == q->val) return root;
    int small = min(p->val, q->val);
    int large = max(p->val, q->val);
    if(root->val<=large && root->val>=small) return root;
    if(root->val<small) return lowestCommonAncestor(root->right, p, q);
    else return lowestCommonAncestor(root->left, p, q);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    //iterative
    if(!root || !p || !q) return NULL;
    int l = min(p->val, q->val), r = max(p->val, q->val);
    while(root){
        if(root->val>=l && root->val<=r) return root;
        else if(root->val<l) root = root->right;
        else root = root->left;
    }
    return root;
}

int main(){
    TreeNode* root = create_tree("6280479##35");
    TreeNode* res = lowestCommonAncestor(root, root->left, root->left->right);
    if(!res) cout<<"NULL";
    else cout<<res->val;
    cout<<endl;
    return 0;
}