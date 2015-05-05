#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    // morris traversal
    vector<int> res;
    if(!root) return res;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){
            res.push_back(curr->val);
            curr = curr->right;
            continue;
        }
        TreeNode* x = curr->left;
        while(x->right && x->right != curr) x = x->right;
        if(x->right == curr){
            res.push_back(curr->val);
            curr = curr->right;
        }
        else{
            x->right = curr;
            curr = curr->left;
        }
    }
    return res;
}

int main(){
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    one.left = &two;
//    one.right = &two;
//    two.left = &three;
    vector<int> res = inorderTraversal(&one);
//    three.left = &one;
//    three.right = &two;
//    vector<int> res = postorderTraversal(&three);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
